import sys

def debug(s):
	sys.stderr.write(str(s))


def solve():
	n = int(input())
	print(n)
	debug([1,2,3,4,5])

if __name__=="__main__":
	sys.stdin=open("in.txt", 'r')
	sys.stdout=open("out.txt", 'w')
	sys.stderr=open("error.txt", 'w')
	solve()

	sys.stdin.close()
	sys.stdout.close()
	sys.stderr.close()

