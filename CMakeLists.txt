cmake_minimum_required(VERSION 3.19)

project(
    pyopenfhe
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenFHE REQUIRED)
include_directories(${OpenFHE_INCLUDE}/core)
include_directories(${OpenFHE_INCLUDE}/pke)
include_directories(${OpenFHE_INCLUDE}/binfhe)
include_directories(${OpenFHE_INCLUDE})

add_subdirectory(dependencies/pybind)
add_subdirectory(src)

#pybind11_add_module(add_m src/module.cpp)
#target_link_libraries(add_m PRIVATE ${OpenFHE_LIBRARIES})
#
#pybind11_add_module(ctx src/binfhe.cpp)
#target_link_libraries(ctx PRIVATE ${OpenFHE_LIBRARIES})
#
#add_executable(run src/main.cpp)
#target_link_libraries(run PRIVATE ${OpenFHE_LIBRARIES})
