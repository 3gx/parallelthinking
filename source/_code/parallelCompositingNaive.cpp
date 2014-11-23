#include <mpi.h>
#include <memory>
#include <vector> 
struct float4
{
  float x,y,z,w;
};
void parallelCompositingNaive(
    std::shared_ptr<float4> src, 
    std::shared_ptr<float4> dst, 
    const int npixels, 
    const MPI_Comm &comm,
    const std::vector<int> &compositingOrder)
{
  int rank = -1;
  int nrank = 0;
  if (rank < 0)
  {
    MPI_Comm_size(comm, &nrank);
    MPI_Comm_rank(comm, &rank);
  }
  const int nsend = (npixels+nrank-1)/nrank;
  static std::vector<float4> colorArray;
  colorArray.resize(nsend*nrank);
    
  MPI_Alltoall(src.get(), nsend*4, MPI_FLOAT, &colorArray[0], nsend*4, MPI_FLOAT, comm);

#pragma omp parallel for schedule(static)
  for (int i = 0; i < nsend; i++)
  {
    const int stride = i*nrank;
    float4 _dst = {0.0f,0.0f,0.0f,0.0f};
    for (auto p : compositingOrder)
    {
      const float4 &_src = colorArray[p*nsend+i];
      const float f = 1.0f - _dst.w;
      _dst.x += _src.x * f;
      _dst.y += _src.y * f;
      _dst.z += _src.z * f;
      _dst.w += _src.w * f;
    }
    colorArray[i] = _dst;
  }
  
  MPI_Gather(&colorArray[0], nsend*4, MPI_FLOAT, dst.get(), 4*nsend, MPI_FLOAT, 0, comm);
}
