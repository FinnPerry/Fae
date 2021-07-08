# fae

## Build instructions:

### Linux:

- Install dependencies:
    - `sudo apt install -y cmake build-essential g++`
    - Build and install glfw3 from https://github.com/glfw/glfw.git
        - Make sure to run `make install`
- Build fae:
    - Navigate to the fae/scripts/linux/ folder
    - `bash re-configure`
    - `bash build-and-run-demo`
    - Those 2 scripts will fully rebuild and run the project. Individual build steps can be performed by running the following scripts:
        - `bash clean` to delete build files
        - `bash configure` to generate build scripts
        - `bash build` to compile
        - `bash run-demo` to run the demo exe

### Windows:

- Install dependencies:
    - Install cmake
    - Install msvc
    - Build and install glfw3 from https://github.com/glfw/glfw.git
        - Make sure to run `cmake --install`
- Build fae:
    - Open msvc dev cmd. (This is required for build.bat and by extension build-and-run-demo.bat. Other scripts can be run in a normal terminal or by double clicking.)
    - Navigate to the fae/scripts/windows/ folder
    - `call re-configure.bat`
    - `call build-and-run-demo.bat`
    - Those 2 scripts will fully rebuild and run the project. Individual build steps can be performed by running the following scripts:
        - `call clean.bat` to delete build files
        - `call configure.bat` to generate build scripts
        - `call build.bat` to compile
        - `call run.bat-demo` to run the demo exe
