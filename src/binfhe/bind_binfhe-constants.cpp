#include "bind_binfhe-constants.h"

#include <openfhe/binfhe/binfhe-constants.h>

using namespace lbcrypto;
namespace py = pybind11;

namespace bind::binfhe {

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
}
