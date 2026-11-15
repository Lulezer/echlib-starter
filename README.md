# echlib-starter

Smallest CMake project that pulls in [Echlib](https://github.com/Lulezer/Echlib-Library) as a submodule.

## Requirements

CMake 3.16+, MSVC 2022 (or another C++17 toolchain), Windows for now.

## Build

```powershell
git clone --recurse-submodules https://github.com/Lulezer/echlib-starter.git
cd echlib-starter
cmake -S . -B build
cmake --build build --config Release
.\build\Release\echlib-starter.exe
```

Already cloned without submodules?

```powershell
git submodule update --init --recursive
```

Custom library path:

```powershell
cmake -S . -B build -DECHLIB_ROOT="C:/dev/Echlib-Library"
```

## Project layout

```
echlib-starter/
  CMakeLists.txt      # add_subdirectory(thirdparty/echlib)
  src/main.cpp        # your game
  thirdparty/echlib/  # git submodule → Echlib-Library
```

## clangd

Add a `.clangd` with `-I` paths into `thirdparty/echlib/include` and glm/stb under `thirdparty/echlib/thirdparty` if you use the clangd extension.