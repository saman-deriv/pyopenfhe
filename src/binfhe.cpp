#include <pybind11/pybind11.h>
#include <openfhe/binfhe/binfhecontext.h>
#include <memory>

using namespace lbcrypto;
namespace py = pybind11;

void bind_BINGATE(py::module &m) {
    py::enum_<BINGATE>(m, "BINGATE")
        .value("OR", BINGATE::OR)
        .value("AND", BINGATE::AND)
        .value("NOR", BINGATE::NOR)
        .value("NAND", BINGATE::NAND)
        .value("XOR_FAST", BINGATE::XOR_FAST)
        .value("XNOR_FAST", BINGATE::XNOR_FAST)
        .value("XOR", BINGATE::XOR)
        .value("XNOR", BINGATE::XNOR)
        .export_values();
}

void bind_BINFHE_PARAMSET(py::module &m) {
    py::enum_<BINFHE_PARAMSET>(m, "BINFHE_PARAMSET")
        .value("TOY", BINFHE_PARAMSET::TOY)
        .value("MEDIUM", BINFHE_PARAMSET::MEDIUM)
        .value("STD128_AP", BINFHE_PARAMSET::STD128_AP)
        .value("STD128_APOPT", BINFHE_PARAMSET::STD128_APOPT)
        .value("STD128", BINFHE_PARAMSET::STD128)
        .value("STD128_OPT", BINFHE_PARAMSET::STD128_OPT)
        .value("STD192", BINFHE_PARAMSET::STD192)
        .value("STD192_OPT", BINFHE_PARAMSET::STD192_OPT)
        .value("STD256", BINFHE_PARAMSET::STD256)
        .value("STD256_OPT", BINFHE_PARAMSET::STD256_OPT)
        .value("STD128Q", BINFHE_PARAMSET::STD128Q)
        .value("STD128Q_OPT", BINFHE_PARAMSET::STD128Q_OPT)
        .value("STD192Q", BINFHE_PARAMSET::STD192Q)
        .value("STD192Q_OPT", BINFHE_PARAMSET::STD192Q_OPT)
        .value("STD256Q", BINFHE_PARAMSET::STD256Q)
        .value("STD256Q_OPT", BINFHE_PARAMSET::STD256Q_OPT)
        .value("SIGNED_MOD_TEST", BINFHE_PARAMSET::SIGNED_MOD_TEST)
        .export_values();
}

void bind_BINFHE_METHOD(py::module &m) {
    py::enum_<BINFHE_METHOD>(m, "BINFHE_METHOD")
        .value("AP", BINFHE_METHOD::AP)
        .value("GINX", BINFHE_METHOD::GINX)
        .export_values();
}

void bind_BINFHE_OUTPUT(py::module &m) {
    py::enum_<BINFHE_OUTPUT>(m, "BINFHE_OUTPUT")
        .value("BOOTSTRAPPED", BINFHE_OUTPUT::BOOTSTRAPPED)
        .value("SMALL_DIM", BINFHE_OUTPUT::SMALL_DIM)
        .value("LARGE_DIM", BINFHE_OUTPUT::LARGE_DIM)
        .value("FRESH", BINFHE_OUTPUT::FRESH)
        .export_values();
}

void bind_KEYGEN_MODE(py::module &m) {
    py::enum_<KEYGEN_MODE>(m, "KEYGEN_MODE")
        .value("SYM_ENCRYPT", KEYGEN_MODE::SYM_ENCRYPT)
        .value("PUB_ENCRYPT", KEYGEN_MODE::PUB_ENCRYPT)
        .export_values();
}

void bind_LWEPrivateKeyImpl(py::module &m) {
    py::class_<LWEPrivateKeyImpl, std::shared_ptr<LWEPrivateKeyImpl>>(m, "LWEPrivateKeyImpl")
            .def(py::init<>());
}

void bind_LWECiphertextImpl(py::module &m) {
    py::class_<LWECiphertextImpl, std::shared_ptr<LWECiphertextImpl>>(m, "LWECiphertextImpl")
            .def(py::init<>());
}

void bind_LWEPublicKeyImpl(py::module &m) {
    py::class_<LWEPublicKeyImpl, std::shared_ptr<LWEPublicKeyImpl>>(m, "LWEPublicKeyImpl")
            .def(py::init<>());
}

template <typename T>
void bind_NativeIntegerT(py::module &m) {
    py::class_<intnat::NativeIntegerT<T>, std::shared_ptr<intnat::NativeIntegerT<T>>>(m, "NativeIntegerT")
            .def(py::init<T>());
}

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

PYBIND11_MODULE(ctx, m) {
        m.doc() = "Library for doing homomorphic encryption operations on tensors";
        bind_BINGATE(m);
        bind_BINFHE_PARAMSET(m);
        bind_BINFHE_METHOD(m);
        bind_BINFHE_OUTPUT(m);
        bind_KEYGEN_MODE(m);

        bind_LWEPrivateKeyImpl(m);
        bind_LWEPublicKeyImpl(m);
        bind_LWECiphertextImpl(m);
        bind_NativeIntegerT<BasicInteger>(m);
        bind_BinFHEContext(m);
}
