# Template For C++ Projects

![C++](https://camo.githubusercontent.com/c59efb57803dde7f352f4932a468a7f39fa2fb5f/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f632532422532422d31312f31342f31372f32302d626c75652e737667)
![License](https://camo.githubusercontent.com/890acbdcb87868b382af9a4b1fac507b9659d9bf/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4d49542d626c75652e737667)

This is a template for Imgui C++ projects. What you get:

- Library and executable code separated in distinct folders.
- Use of modern CMake for building and compiling.
- External libraries:
  - All graphical and imgui related libs via Git submodules:
    - GLFW, Imgui and Implot
  - General purpose libraries via CMake FetchContent:
    - [JSON](https://github.com/nlohmann/json), [spdlog](https://github.com/gabime/spdlog) ,[cxxopts](https://github.com/jarro2783/cxxopts) and [fmt](https://github.com/fmtlib/fmt)

## Structure

``` text
├── CMakeLists.txt
├── app
│   ├── CMakesLists.txt
│   └── main.cc
├── cmake
│   └── cmake modules
├── external
│   ├── CMakesLists.txt
│   └── ...
└── src
    ├── CMakesLists.txt
    ├── my_lib.h
    └── my_lib.cc
   
```

Library code goes into [src/](src/), main program code in [app/](app).

## Software Requirements

- CMake 3.16+
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)

## Building

First, clone this repo and do the preliminary work:

```shell
git clone --recursive https://github.com/franneck94/ImGuiProjectTemplate.git
```

- App Executable

```shell
cd build
cmake  ..
cmake --build . --target main
cd bin
./main
```
