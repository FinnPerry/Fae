# fae

## Build instructions:

- Install dependencies:
    - `sudo apt install -y cmake build-essential g++`
    - Build and install glfw3 from https://github.com/glfw/glfw.git
- Build fae:
    - Navigate to the fae/scripts/ folder
    - Run build scripts:
        - `bash configure` to generate build files
        - `bash build` to build the project
    - Other scripts:
        - `bash clean` to delete generated build files
        - `bash run` to run the demo project
        - `bash full` to fully re-build everything and run the demo project
