import sys

def debug(s):
	sys.stderr.write(str(s) + '\n')


def solve():
	line = ''
	ladder = {}
	snake = {}
	end = 100
	start=end-10
	f=False
	for i in range(10):
		line = input().split(" ")
		#debug(line)
		r = None
		if not f:
			r= range(end,start, -1)
		else:
			r= range(start+1,end+1)
		f=not f
		# debug(r)
		# debug(len(r))
		# debug(len(line))
		for each,idx in zip(line,r):
			# debug((each,idx))
			if ('L(' in each) or ('S(' in each) :
				spl = each.split("(")
				val = spl[1][0:-1]
				if spl[0]=='S':
					snake[idx]= int(val) if val!='Start' and val!='End' else 0 if val=='Start' else 100
				else:

					ladder[idx]= int(val) if val!='Start' and val!='End' else 0 if val=='Start' else 100

		end -=10
		start=end-10

	# debug(snake)
	# debug(ladder)

	values = list(map(int,input().split()))

	curr = 0
	sC = 0
	lC = 0

	for each in values:
		curr += each
		if curr in snake:
			curr = snake[curr]
			sC+=1
		if curr in ladder:
			curr = ladder[curr]
			lC+=1

		if curr==100:
			break
	if curr==100:
		print('Possible',sC,lC)
	else:
		print('Not possible',sC,lC,curr)


if __name__=="__main__":
	sys.stdin=open("in.txt", 'r')
	sys.stdout=open("out.txt", 'w')
	sys.stderr=open("error.txt", 'w')
	solve()

	sys.stdin.close()
	sys.stdout.close()
	sys.stderr.close()
