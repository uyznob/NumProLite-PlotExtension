# NumProLite-PlotExtension
Code examples to add plotting extensions into existing project “NumPro Lite”<br />
In the following, I demonstrate how to add two newly-coded methods to the existing project “NumPro Lite” in order to plot the initial and deformed mesh. Matplotlibcpp is the only necessary dependency for these newly-coded methods.<br />
Step 1: Download the project from https://github.com/osolmaz/numpro-lite<br />
Step 2: Setup the project in Visual Studio Code IDE<br />
Step 3: Configure task.json to enable matplotlibcpp<br />
"args": [
        "-fdiagnostics-color=always",<br />
        "-g",<br />
        "${workspaceFolder}/src/**/*.cpp",<br />
        "-I${workspaceFolder}/include/",<br />
        "-DWITHOUT_NUMPY", //matplotlib<br />
        "-I/usr/local/include/python2.7", //matplotlib<br />
        "-lpython2.7", //matplotlib<br />
        "-o",<br />
        "${fileDirname}/${fileBasenameNoExtension}"<br />
      ],<br />
Step 4: Define new methods in the header file Discretization.h<br />
void plot_msh();<br />
void plot_defo_msh();<br />
Step 5: Code new methods plot_msh() and plot_defo_msh() in the C++ file Discretization.cpp<br />
Step 6: Call new methods in the NumPro class<br />
// Plot initial mesh<br />
discretization->plot_msh();<br />
// Plot deformed mesh<br />
discretization->plot_defo_msh();<br />
Step 7: Plots and results
