import binfhe
import math

cc = binfhe.BinFHEContext()

logQ = 23
cc.GenerateBinFHEContext(binfhe.STD128, False, logQ, 0, binfhe.GINX, True)

Q = 1 << logQ
q = 4096
factor = 1 << int(logQ - math.log2(q))

p = cc.GetMaxPlaintextSpace().ConvertToInt()
P = p * factor

sk = cc.KeyGen()
cc.BTKeyGen(sk, binfhe.SYM_ENCRYPT)

ct1 = cc.Encrypt(sk, int(P / 2 + 1), binfhe.FRESH, P, binfhe.NativeInteger(Q))
decomp = cc.EvalDecomp(ct1)

for i in range(len(decomp)):
    ct1 = decomp[i]
    if (i == len(decomp) - 1):
        logp = GetMSB(P - 1) % GetMSB(p - 1)
        p = 1 << logp
    result = cc.Decrypt(sk, ct1, p)
    print("(",result, " * ", cc.GetMaxPlaintextSpace(), "^", i, ")")
    if (i != len(decomp) - 1):
        print(" + ")

print("\n")
