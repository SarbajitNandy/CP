n,m = map(int , input().strip().split(" "))

pList = ['8','18','11','15','5','4','14','9','19','1','7','17','6','16','10','3','13','2','12','0']

if (n>m):
	om, on = 0,1
elif n==m:
	print(n)
	exit(0)
else:
	om, on = 1,0

ans = n+m
flag,i,j = 0,0,0
while (n <= 99999 and m <= 99999 ):
	ln,lm = str(n),str(m)
	if (len(ln) <= len(lm)):
		l = len(ln)
	else:
		l = len(lm)

	#print(ln,lm)
	while (len(ln)!=0 and len(lm)!=0):
		#print(ln[i], lm[i], i)
		#print(pList.index(ln[i]),pList.index(lm[i]))
		if len(ln)%2==1 and len(ln)>3 and int(ln[0:2])<20:
			dn = ln[0:2]
			ln = ln[2:]
		else:
			dn = ln[0]
			ln = ln[1:]
		if len(lm)%2==1 and len(lm)>3 and int(lm[0:2])<20:
			dm = lm[0:2]
			lm = lm[2:]
		else:
			dm = lm[0]
			lm = lm[1:]
		#print(dn ,dm)
		#print(ln,lm)
		if dn=='0':
			if dm!='0':
				if om==0:
					ans = m+n;
					flag = 1
					break;
		elif dm=='0':
			if dn!='0':
				if on==0:
					ans = m+n
					flag = 1
					break
		elif pList.index(dn) > pList.index(dm):
			if om==1:
				ans = n+m
				flag = 1
			break
		elif pList.index(dn) < pList.index(dm):
			if on==1:
				ans = n+m
				flag = 1
			break
		else:
			continue
		#print(n,m)
	if flag:
		break
	else:
		n,m=n*2,m*2
                
if n > 99999 or m > 99999 :
	print("Out of bounds")
else:
	print(ans)
