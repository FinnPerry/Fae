# fae

## Build instructions:

### Linux:

- Install dependencies:
    - `sudo apt install -y cmake build-essential g++`
    - Build and install glfw3 from https://github.com/glfw/glfw.git
        - Make sure to run `make install`
- Build fae:
    - Navigate to the fae/scripts/linux/ folder
    - Run build scripts:
        - `bash configure` to generate build files
        - `bash build` to build the project
    - Other scripts:
        - `bash clean` to delete generated build files
        - `bash run` to run the demo project
        - `bash full` to fully re-build everything and run the demo project

### Windows:

- Install dependencies:
    - Install cmake
    - Install msvc
    - Build and install glfw3 from https://github.com/glfw/glfw.git
        - Make sure to run `cmake --install`
- Build fae:
    - Open msvc dev cmd
    - Navigate to the fae/scripts/windows/ folder
    - Run build scripts:
        - `call configure.bat` to generate build files
        - `call build.bat` to build the project
    - Other scripts:
        - `call clean.bat` to delete generated build files
        - `call run.bat` run the demo project
        - `call full.bat` to fully re-build everything and run the demo project
