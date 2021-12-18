import sys

def debug(s):
	sys.stderr.write(str(s) + "\n")

def check(s):
	dp=dict()
	odd=0
	for each in s:
		if dp.get(each,0)&1:
			odd-=1
		else:
			odd+=1
		dp[each]=dp.get(each,0)+1
	return not (odd>1)

def go(n,s):
	dp = dict()
	mx=-1
	for i in range(n):

		if check(s[0:i+1]):
			mx=max(mx,i+1)
			debug({'front':i, "mx":mx})
		if check(s[i:n]):
			mx=max(mx,n-i)
			debug({'back':i, "mx":mx})
	return n-mx

def solve():
	t=int(input())
	for _ in range(t):
		n=int(input())
		s=input()

		print(go(n,s))

if __name__=="__main__":
	sys.stdin=open("in.txt", 'r')
	sys.stdout=open("out.txt", 'w')
	sys.stderr=open("error.txt", 'w')
	solve()

	sys.stdin.close()
	sys.stdout.close()
	sys.stderr.close()

