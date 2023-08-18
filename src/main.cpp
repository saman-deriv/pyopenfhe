#include <iostream>

#include <openfhe/pke/openfhe.h>

using namespace lbcrypto;

int main() {
    CCParams<CryptoContextBFVRNS> parameters;
    parameters.SetPlaintextModulus(65537);
    parameters.SetMultiplicativeDepth(2);
}
