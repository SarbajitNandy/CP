arr = input().strip()
q = int(input())

l = len(arr)
first = []
t=[]
start,i = 0,0
if q > l :
	print("NO")
else:
	while i < q:
		t = input().strip().split(" ")
		if t[0]=="L":
			start += (int(t[1])%l)
		else:
			start -= (int(t[1])%l)
		first.append(arr[start])
		i+=1

	#arr = sorted(arr)
	first = str(sorted(first))
	#print(arr, first)

	for i in range(l):
		if arr[i] in first:
			#print(arr[i:i+3])
			if str(sorted(arr[i:i+q])) == first:
				print("YES")
				exit(0)

	print("NO")