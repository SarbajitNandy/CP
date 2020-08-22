def same():
	for i,j in zip(la,lb):
		if (i!=j):
			return 0	
	return 1

a,b = input().split(" ")



la= [0]*10
lb= [0]*10
b = list(b)

n = []

if ( len(a) == len(b)):
	for i,j in zip(a,b):
		la[int(i)] += 1 
		lb[int(j)] += 1

	if (not same()):
		s = -1
		for i in range(1,len(b)):
			if (b[i-1] < b[i]):
				s = i-1
		# print(s)
		for i in b:
			x = None
			if s!=0 and la[int(i)]:
				n.append(i)
				la[int(i)] -= 1
			else:
				for k in range(int(i)+1, 10 ):
					if la[k]:
						x = k
						break

				if x:
					n.append(str(x))
					la[x] -= 1

					for i in range(0,10):
						if la[i]:
							n.append(str(i)*la[i])

					print("".join(n))
				else:
					print(-1)
				exit()
	else :
		s = -1
		for i in range(1,len(b)):
			if (b[i-1] < b[i]):
				s = i-1
		# print(s)
		for i in range(len(b)):
			if i!=s and la[int(b[i])] :
				n.append(b[i])
				la[int(b[i])] -= 1
			else:
				x = None;
				for k in range(int(b[i])+1, 10 ):
					if la[k]:
						x = k
						break

				if x:
					n.append(str(x))
					la[x] -= 1

					for i in range(0,10):
						if la[i]:
							n.append(str(i)*la[i])
					print("".join(n))

				else:
					print(-1)
				exit(0)
		print(-1)
		exit(0)

else:
	print(-1)

# print(la)
