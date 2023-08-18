#include "bind_lwe-publickey.h"

#include <openfhe/binfhe/lwe-publickey.h>
#include <memory>

using namespace lbcrypto;
namespace py = pybind11;

namespace bind::binfhe {
void bind_LWEPublicKeyImpl(py::module &m) {
    py::class_<LWEPublicKeyImpl, std::shared_ptr<LWEPublicKeyImpl>>(m, "LWEPublicKeyImpl")
            .def(py::init<>());
}
}
