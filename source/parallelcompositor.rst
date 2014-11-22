Massively parallel image compositing
======================================

This is a technical follow-up on my short piece about `interactive
supercomputing <http://tailvega.com/hpc005.html>`_. Here I focus on challenges
we faced, and the solution which allowed us to scale the visualization engine
to thousand of GPUs while maintaining a good degree of interactivity.

Parallel image compositing is one of the final stages of sort-last parallel
rendering, in which the partial images from separate rendering workers are
being blended into the final image. This is both compute and communication
heavy rendering steps, which is absent when image is rendered on a single
worker.

.. image:: ./_images/logo.png
    :width: 200px
    :align: center
    :height: 100px
    :alt: alternate text test

Test1

.. figure:: ./_images/logo.png
    :width: 200px
    :align: center
    :height: 100px
    :alt: alternate text test

    **Figure 1**: figure is like an images but with a capture.


Test2

.. math::
  
   W^{3\beta}_{\delta_1 \rho_1 \sigma_2} \approx U^{3\beta}_{\delta_1 \rho_1}

.. code-block:: c++

   class A
   {
     private:
      int foo;
     public:
      A(const int _foo) : foo(_foo) {}
      int get_foo() const {return foo; }
      void set_foo(const int _foo) { foo = _foo; }
   };

   int main(int argc, char * argv[])
   {
     A a(argc);
     retrun 0;
   }

Test code block & math
