file (GLOB PKE_BIND_FILES CONFIGURE_DEPENDS *.cpp)

pybind11_add_module(pke ${PKE_BIND_FILES} ${CORE_SRC})
target_link_libraries(pke PRIVATE ${OpenFHE_LIBRARIES})

file(COPY examples/ DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
