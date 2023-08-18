#include "bind_binfhecontext.h"

#include <openfhe/binfhe/binfhecontext.h>
#include <memory>

using namespace lbcrypto;
namespace py = pybind11;

namespace bind::binfhe {
void bind_BinFHEContext(py::module &m) {
    py::class_<BinFHEContext, std::shared_ptr<BinFHEContext>>(m, "BinFHEContext")
            .def(py::init<>()) 
            .def("GenerateBinFHEContext", py::overload_cast<uint32_t, uint32_t,
                    const NativeInteger&, const NativeInteger&, double, uint32_t, uint32_t,
                    uint32_t, BINFHE_METHOD>(&BinFHEContext::GenerateBinFHEContext),
                    "Creates a crypto context using custom parameters")
            .def("GenerateBinFHEContext", py::overload_cast<BINFHE_PARAMSET, bool, uint32_t,
                    int64_t, BINFHE_METHOD, bool>(&BinFHEContext::GenerateBinFHEContext),
                    "Creates a crypto context using custom parameters")
            .def("GenerateBinFHEContext", py::overload_cast<BINFHE_PARAMSET, BINFHE_METHOD>(
                        &BinFHEContext::GenerateBinFHEContext),
                        "Creates a crypto context using custom parameters")
            .def("Decrypt", [](BinFHEContext& ctx, ConstLWEPrivateKey sk, ConstLWECiphertext ct, LWEPlaintextModulus p) -> LWEPlaintext {
                LWEPlaintext result;
                ctx.Decrypt(sk, ct, &result, p);
                return result;
                })
            .def("BTKeyGen", &BinFHEContext::BTKeyGen)
            .def("BTKeyLoad", &BinFHEContext::BTKeyLoad)
            .def("BTKeyMapLoadSingleElement", &BinFHEContext::BTKeyMapLoadSingleElement)
            .def("Bootstrap", &BinFHEContext::Bootstrap)
            .def("ClearBTKeys", &BinFHEContext::ClearBTKeys)
            .def("Encrypt", static_cast<LWECiphertext (BinFHEContext::*)(ConstLWEPrivateKey, LWEPlaintext, BINFHE_OUTPUT, LWEPlaintextModulus, const NativeInteger&) const>(&BinFHEContext::Encrypt))
            .def("Encrypt", static_cast<LWECiphertext (BinFHEContext::*)(ConstLWEPublicKey, LWEPlaintext, BINFHE_OUTPUT, LWEPlaintextModulus, const NativeInteger&) const>(&BinFHEContext::Encrypt))
            .def("EvalBinGate", &BinFHEContext::EvalBinGate)
            .def("EvalConstant", &BinFHEContext::EvalConstant)
            .def("EvalDecomp", &BinFHEContext::EvalDecomp)
            .def("EvalFloor", &BinFHEContext::EvalFloor)
            .def("EvalFunc", &BinFHEContext::EvalFunc)
            .def("EvalNOT", &BinFHEContext::EvalNOT)
            .def("EvalSign", &BinFHEContext::EvalSign)
            .def("GenerateLUTviaFunction", &BinFHEContext::GenerateLUTviaFunction)
            .def("GetBTKeyMap", &BinFHEContext::GetBTKeyMap)
            .def("GetBTKeyMap", &BinFHEContext::GetBTKeyMap)
            .def("GetBeta", &BinFHEContext::GetBeta)
            .def("GetBinFHEScheme", &BinFHEContext::GetBinFHEScheme)
            .def("GetLWEScheme", &BinFHEContext::GetLWEScheme)
            .def("GetMaxPlaintextSpace", &BinFHEContext::GetMaxPlaintextSpace)
            .def("GetParams", &BinFHEContext::GetParams)
            .def("GetPublicKey", &BinFHEContext::GetPublicKey)
            .def("GetRefreshKey", &BinFHEContext::GetRefreshKey)
            .def("GetRefreshKey", &BinFHEContext::GetRefreshKey)
            .def("GetSwitchKey", &BinFHEContext::GetSwitchKey)
            .def("GetSwitchKey", &BinFHEContext::GetSwitchKey)
            .def("KeyGen", &BinFHEContext::KeyGen)
            .def("KeyGenN", &BinFHEContext::KeyGenN)
            .def("KeyGenPair", &BinFHEContext::KeyGenPair)
            .def("KeySwitchGen", &BinFHEContext::KeySwitchGen)
            .def("PubKeyGen", &BinFHEContext::PubKeyGen)
            .def("SwitchCTtoqn", &BinFHEContext::SwitchCTtoqn);
}
}
