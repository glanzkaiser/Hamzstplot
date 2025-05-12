# Hamzstplot
C++ plotting library for scientist and engineer based on Matplot 1.2.0.

On May 12th, 2025: We are forking / branching out from Matplot 1.2.0 made by Alan Freitas(thanks for his hard work on Matplot) because we want to modify it for our own science and engineering learning.
To be a better scientist and engineer, we need to plot, simulate the 2D and 3D representation of a function or more than one function.

The reason to create this is to learn more on how to create a plotting library with C++, before we can even develop this with new features that we want. 

We have SymIntegration library, and it can compute several integral computations, if we can plot the result of an integrated function with this, then it will be great. Even with backend still need Gnuplot or OpenGL, the raw coding with C++ to plot a function is really helpful.


# Build and Install

In GFreya OS all the dependencies are already installed, from Gnuplot, CMake to GCC with C++17, OpenGL with its friends -> GLAD, GLFW.

For other Linux-based OS or for MacOS user or Windows user, you can check on Matplot 1.2.0 if this method cannot work on you, since we are still in infant stage of trying this plotting library.

=== "GFreya OS / CAELinux / Ubuntu / Linux-Based OS + GCC"

Open terminal and from the current working directory / this repository main directory:

```bash
mkdir build
cd build
cmake -DBUILD_SHARED_LIBS=ON .. 
make
make install
```

You can make the compiling faster with `make -j4`, to add parallel jobs.

This will create the shared library named `libhamzstplot.so` and it will be installed by default at `/usr/local/` directory.

* Don't forget to move the include files from `CImg` and `nodesoup` into your `/usr/include/`or `/usr/local/include` directory path.

By default the CMake will make a static library for nodesoup, but in the directory `/source/3rd_party/nodesoup/src` we already provide the dynamic / shared library.

<img src="https://github.com/glanzkaiser/Hamzstplot/blob/main/images/1.png" width="37%">

<img src="https://github.com/glanzkaiser/Hamzstplot/blob/main/images/2.png" width="37%">

<img src="https://github.com/glanzkaiser/Hamzstplot/blob/main/images/3.png" width="37%">

## Dependencies

**C++17**
**CMake 3.14+**
**Gnuplot 5.2.6+**

# Examples Built from CMake

A small amount of examples are built when you are compiling with CMake / the method mentioned above.

To see the plot that can be generated, from the `build` directory that you have created open terminal and type

```bash
cd examples/line_plot/fplot/
./example_fplot_1

```

<img src="https://github.com/glanzkaiser/Hamzstplot/blob/main/images/4.png" width="37%">

<img src="https://github.com/glanzkaiser/Hamzstplot/blob/main/images/5.png" width="37%">

# Examples with Manual Way

Open terminal and from the current working directory / this repository main directory:

```
	cd Examples with Makefile/Plot 3D Helix
	make
	./main
```

If you prefer the old way then you can compile the old way / type `g++ main.cpp -o main -lhamzstplot` instead of typing `make`.

You can edit / modify the `main.cpp` file here to plot different function. The example here is a parametric function of a helix.

<img src="https://github.com/glanzkaiser/Hamzstplot/blob/main/images/6.png" width="37%">

<img src="https://github.com/glanzkaiser/Hamzstplot/blob/main/images/7.png" width="37%">
