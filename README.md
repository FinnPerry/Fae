# fae

## Build instructions:

### Linux:

- Install dependencies:
    - `sudo apt install -y cmake build-essential g++`
    - Build and install glfw3 from https://github.com/glfw/glfw.git
        - Make sure to run `make install`
- Build fae:
    - Navigate to the fae/scripts/linux/ folder
    - The following scripts can be used to build the project:
        - `./clean` to delete build files
        - `./configure` to generate build scripts
        - `./build` to compile
        - `./run-demo` to run the demo exe
    - To perform a full re-build, run the scripts in a chain:
        - `./clean && ./configure && ./build && ./run-demo`

### Windows:

- Install dependencies:
    - Cmake
    - Visual Studio
    - Ninja
    - glfw3
        - Note that the cmake scripts assume glfw has been installed using `cmake --install`
            (or otherwise placed in the same location)
- Build fae:
    - Open Visual Studio Native Tools cmd (x86 or x64 depending on what glfw3 version you have)
    - Navigate to the fae\scripts\windows\ folder
    - The following scripts can be used to build the project:
        - `call clean.bat` to delete build files
        - `call configure.bat` to generate build scripts
        - `call build.bat` to compile
        - `call run-demo.bat` to run the demo exe
    - To perform a full re-build, run the scripts in a chain:
        - `call clean.bat && call configure.bat && call build.bat && call run-demo.bat`
