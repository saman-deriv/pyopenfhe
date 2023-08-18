import binfhe

cc = binfhe.BinFHEContext()
cc.GenerateBinFHEContext(binfhe.STD128, binfhe.GINX)

sk = cc.KeyGen()
cc.BTKeyGen(sk, binfhe.SYM_ENCRYPT)

ni = binfhe.NativeInteger()

ct1 = cc.Encrypt(sk, 1, binfhe.BOOTSTRAPPED, 4, ni)
ct2 = cc.Encrypt(sk, 1, binfhe.BOOTSTRAPPED, 4, ni)

ctAND1 = cc.EvalBinGate(binfhe.AND, ct1, ct2)
ct2Not = cc.EvalNOT(ct2)
ctAND2 = cc.EvalBinGate(binfhe.AND, ct2Not, ct1)
ctResult = cc.EvalBinGate(binfhe.OR, ctAND1, ctAND2)

result = cc.Decrypt(sk, ctResult, 4)

print(result)
