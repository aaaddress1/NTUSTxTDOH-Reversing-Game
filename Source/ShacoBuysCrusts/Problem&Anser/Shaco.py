#!/usr/bin/env python2.7
#By aaaddress1.
from z3 import *

b = [ BitVec("b%d" % i, 32) for i in range(16)]
Tmp = [ BitVec("b%d" % i, 32) for i in range(16)]
s = Solver()

for i in range(13):
	s.add(b[i] == ord("KEY=sexy&!kno"[i]))
	print("KEY=sexy&!know!t"[i])
s.add(b[14] == ord('!'))

for i in "KTqncrPvd R'NSB\\;mY^fkhAGWDC<O@7VJ>XQ,\"U/Zp:bl":
	s.add(b[13] != ord(i))


extr = 0
vSum = 0
for i in range(16):
	s.add((b[i] & 0xff) == b[i])
	s.add(b[i] >= 0x20)
	s.add(b[i] <= 0x7E)
	vSum += b[i] * i + extr
	extr += (vSum%10) +( vSum/10)


s.add(vSum == 59842)

print(s.check())

m = s.model()
res = ''
for i in range(16):
	g = m[b[i]]
	inta = int(str(g))
	res += chr(inta & 0xff)

print("Key is %s" % res)
