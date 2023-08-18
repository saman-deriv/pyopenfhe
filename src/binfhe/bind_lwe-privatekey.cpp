#include "bind_lwe-privatekey.h"

#include <openfhe/binfhe/lwe-privatekey.h>
#include <memory>

using namespace lbcrypto;
namespace py = pybind11;

namespace bind::binfhe {
void bind_LWEPrivateKeyImpl(py::module &m) {
    py::class_<LWEPrivateKeyImpl, std::shared_ptr<LWEPrivateKeyImpl>>(m, "LWEPrivateKeyImpl")
            .def(py::init<>());
}
}
