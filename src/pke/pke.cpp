#include <pybind11/pybind11.h>

namespace bind {

PYBIND11_MODULE(pke, m) {
        m.doc() = "Library for doing homomorphic encryption operations on tensors";
}
}
