# fae

## Build instructions:

### Linux:

- Install dependencies:
    - `sudo apt install -y cmake build-essential g++ ninja`
    - glfw3
        - Note that the cmake scripts assume glfw has been installed using `make install`
- Build fae:
    - Navigate to the fae/scripts/linux/ folder
    - Run the following scripts to build and run the project:
        - `./clean` to delete build files
        - `./configure` to generate build scripts
        - `./build` to compile
        - `./run-demo` to run the demo
        - `./run-tests` to run unit tests
    - Scripts can be chained to perform a full rebuild. e.g.
        - `./clean && ./configure && ./build`

### Windows:

- Install dependencies:
    - Cmake
    - Visual Studio
    - Ninja
    - glfw3
        - Note that the cmake scripts assume glfw has been installed using `cmake --install`
- Build fae:
    - Open Visual Studio Native Tools cmd (x86 or x64 depending on what glfw3 version you have)
    - Navigate to the fae\scripts\windows\ folder
    - The following scripts can be used to build the project:
        - `call clean.bat` to delete build files
        - `call configure.bat` to generate build scripts
        - `call build.bat` to compile
        - `call run-demo.bat` to run the demo
        - `call run-tests.bat` to run unit tests
    - Scripts can be chained to perform a full rebuild. e.g.
        - `call clean.bat && call configure.bat && call build.bat`
