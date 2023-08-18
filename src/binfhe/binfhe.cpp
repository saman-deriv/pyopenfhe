#include <pybind11/pybind11.h>

#include <bind_NativeInteger.h>

#include "bind_binfhe-constants.h"
#include "bind_binfhecontext.h"
#include "bind_lwe-ciphertext.h"
#include "bind_lwe-privatekey.h"
#include "bind_lwe-publickey.h"

namespace py = pybind11;

namespace bind {

PYBIND11_MODULE(binfhe, m) {
        m.doc() = "Library for doing homomorphic encryption operations on tensors";
        binfhe::bind_BINGATE(m);
        binfhe::bind_BINFHE_PARAMSET(m);
        binfhe::bind_BINFHE_METHOD(m);
        binfhe::bind_BINFHE_OUTPUT(m);
        binfhe::bind_KEYGEN_MODE(m);

        bind_NativeInteger(m);

        binfhe::bind_LWEPrivateKeyImpl(m);
        binfhe::bind_LWEPublicKeyImpl(m);
        binfhe::bind_LWECiphertextImpl(m);
        binfhe::bind_BinFHEContext(m);
}
}
