#include "bind_NativeInteger.h"

#include <openfhe/core/math/hal.h>
#include <memory>

using namespace lbcrypto;
namespace py = pybind11;

namespace bind {

void bind_NativeInteger(py::module &m) {
    py::class_<NativeInteger, std::shared_ptr<NativeInteger>>(m, "NativeInteger")
            .def(py::init())
            .def(py::init([](int64_t a) { return new NativeInteger(a); }))
            .def("ConvertToInt", [](const NativeInteger& ni) -> int { return ni.ConvertToInt(); });
}

}
