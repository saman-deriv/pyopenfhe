file (GLOB CORE_SRC CONFIGURE_DEPENDS core/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core)

add_subdirectory(binfhe)
