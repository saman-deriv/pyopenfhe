#pragma once

#include <pybind11/pybind11.h>

namespace bind::binfhe {
void bind_LWECiphertextImpl(pybind11::module &m);
}
