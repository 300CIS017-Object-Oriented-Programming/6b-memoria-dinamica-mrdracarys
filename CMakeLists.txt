cmake_minimum_required(VERSION 3.19)
project(TorresNiza)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

add_executable(TorresNiza src/Propietario.cpp  src/Propietario.h  src/CuartoUtil.cpp  src/CuartoUtil.h  src/Propiedad.cpp  src/Propiedad.h  src/Administracion.cpp  src/Administracion.h  src/Main.cpp)

set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
