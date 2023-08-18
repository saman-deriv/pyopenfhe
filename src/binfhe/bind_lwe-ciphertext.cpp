#include "bind_lwe-ciphertext.h"

#include <openfhe/binfhe/lwe-ciphertext.h>
#include <memory>

using namespace lbcrypto;
namespace py = pybind11;

namespace bind::binfhe {
void bind_LWECiphertextImpl(py::module &m) {
    py::class_<LWECiphertextImpl, std::shared_ptr<LWECiphertextImpl>>(m, "LWECiphertextImpl")
            .def(py::init<>());
}
}
