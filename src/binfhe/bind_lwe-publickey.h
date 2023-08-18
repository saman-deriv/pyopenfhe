#pragma once

#include <pybind11/pybind11.h>

namespace bind::binfhe {
void bind_LWEPublicKeyImpl(pybind11::module &m);
}
