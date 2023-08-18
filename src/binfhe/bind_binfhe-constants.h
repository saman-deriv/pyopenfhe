#pragma once

#include <pybind11/pybind11.h>

namespace bind::binfhe {
void bind_BINGATE(pybind11::module &m);
void bind_BINFHE_PARAMSET(pybind11::module &m);
void bind_BINFHE_METHOD(pybind11::module &m);
void bind_BINFHE_OUTPUT(pybind11::module &m);
void bind_KEYGEN_MODE(pybind11::module &m);
}
