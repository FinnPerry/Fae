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
        - `bash clean` to delete build files
        - `bash configure` to generate build scripts
        - `bash build` to compile
        - `bash run-demo` to run the demo exe
    - To perform a full re-build, run the scripts in a chain:
        - `bash clean && bash configure && bash build && bash run-demo`

### Windows:

- Install dependencies:
    - Install cmake
    - Install msvc
    - Build and install glfw3 from https://github.com/glfw/glfw.git
        - Make sure to run `cmake --install`
- Build fae:
    - Open msvc dev cmd. (This is required for build.bat and by extension build-and-run-demo.bat. Other scripts can be run in a normal terminal or by double clicking.)
    - Navigate to the fae/scripts/windows/ folder
    - The following scripts can be used to build the project:
        - `call clean.bat` to delete build files
        - `call configure.bat` to generate build scripts
        - `call build.bat` to compile
        - `call run-demo.bat` to run the demo exe
    - To perform a full re-build, run the scripts in a chain:
        - `call clean.bat && call configure.bat && call build.bat && call run-demo.bat`
