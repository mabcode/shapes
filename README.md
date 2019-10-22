Build Project:
-This project is compliled using Cmake and the build file is not provided. 
-To build this project first navigate to the src directory.
-Once in the src directory make a build directory and cd into it.
-Now that you are in the build directory type "cmake ../" this will connect all the needed files and keep them isolated in the build directory. 
-This will configure your ./shapes, and your tests
-When you run "make", this will enable you to to run the tests connected to the project. The instructions to run the tests are listed in the test section. 

        ====>>>In order compile this file you will need istall or have "Cmake" and "Catch2" <<<===

~Run


Notes:
To spend the least amount of time in Cmake on this assignment I have included a Main.cpp becuse errors are thrown if it is not there while you build. There is a way around this, but do not plan to resolve this probelem as it is not essental for the project to work correctly.

-->>>This project uses OpenGL and will need to be downloaded for the images to be drawn to the screen.
-->>>To install OpenGL on mac type "brew install glfw3"