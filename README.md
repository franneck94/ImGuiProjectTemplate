# Template For C++ Projects

![C++](https://img.shields.io/badge/C%2B%2B-11%2F14%2F17%2F20%2F23-blue)
![License](https://img.shields.io/github/license/franneck94/CppProjectTemplate)
![Linux Build](https://github.com/franneck94/CppProjectTemplate/workflows/Ubuntu%20CI%20Test/badge.svg)

This is a template for C++ projects. What you get:

This is a template for Imgui C++ projects. What you get:

- Library and executable code separated in distinct folders.
- Use of modern CMake for building and compiling.
- External libraries:
  - All graphical and imgui related libs via Git submodules:
    - GLFW, Imgui and Implot
  - General purpose libraries via CMake FetchContent:
    - [JSON](https://github.com/nlohmann/json), [cxxopts](https://github.com/jarro2783/cxxopts) and [fmt](https://github.com/fmtlib/fmt)
- Continuous integration testing with Github Actions and [pre-commit](https://pre-commit.com/)
- Code documentation with [Doxygen](https://doxygen.nl/) and [Github Pages](https://franneck94.github.io/CppProjectTemplate/)
- Tooling: Clang-Format, Cmake-Format, Clang-tidy, Sanitizers

## Structure

``` text
├── CMakeLists.txt
├── app
│   ├── CMakesLists.txt
│   └── main.cc
├── cmake
│   └── cmake modules
├── docs
│   ├── Doxyfile
│   └── html/
├── external
│   ├── CMakesLists.txt
│   ├── ...
├── src
│   ├── CMakesLists.txt
└── ─── render/...
```

Library code goes into [src/](src/), main program code in [app/](app).

## Software Requirements

- CMake 3.21+
- GNU Makefile
- Doxygen
- VCPKG
- MSVC 2017 (or higher), G++9 (or higher), Clang++9 (or higher)

## Building

First, clone this repo and do the preliminary work:

```shell
git clone --recursive https://github.com/franneck94/CppProjectTemplate
mkdir build
```

- App Executable

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target main
cd app
./main
```

- Documentation

```shell
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
cmake --build . --config Debug --target docs
```
