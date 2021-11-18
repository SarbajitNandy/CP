import sys

def solve():
	n = int(input())
	print(n)

if __name__=="__main__":
	sys.stdin=open("in.txt", 'r')
	sys.stdout=open("out.txt", 'w')
	sys.stderr=open("error.txt", 'w')
	solve()

