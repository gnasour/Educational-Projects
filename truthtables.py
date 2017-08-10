def XNOR(p,q):
	return (p and q) or ((not p) and (not q))

for p in [True, False]:
	for q in [True, False]:
		print(p, q, XNOR(p,q))