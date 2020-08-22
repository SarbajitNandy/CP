from itertools import combinations, permutations

a, b = input().split(" ")

s = list("".join(i) for i in list(permutations(a)))

res = list(filter(lambda x: x>b, s))

try:
	r = min(res)

except:
	r = -1

finally:
	print(r)

