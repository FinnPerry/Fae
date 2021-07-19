# fae

## Build instructions:

### Linux:

- Install dependencies:
    - fae dependencies: `sudo apt install -y cmake g++ ninja`
    - glfw dependencies: `sudo apt install -y xorg-dev`
- Build fae:
    - cd into the fae/scripts/linux/ folder
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
    - Visual Studio (with the c++ module)
    - Ninja
- Build fae:
    - Open Visual Studio Native Tools cmd
        - It should come up by searching "Native Tools" in Windows
    - cd into the fae\scripts\windows\ folder
    - Run the following scripts to build and run the project:
        - `call clean.bat` to delete build files
        - `call configure.bat` to generate build scripts
        - `call build.bat` to compile
        - `call run-demo.bat` to run the demo
        - `call run-tests.bat` to run unit tests
    - Scripts can be chained to perform a full rebuild. e.g.
        - `call clean.bat && call configure.bat && call build.bat`
