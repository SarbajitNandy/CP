
def go(i,j):
	if i>n-1 or j>m-1 or vis[i][j] or dp[i][j]=='#':
		return False

	# print(i,j)

	if i==n-1 and j==m-1:
		return True
	if i!=0 or j!=0:
		# print("check")
		vis[i][j] = True
	return go(i,j+1) or go(i+1,j)



if __name__ == '__main__':
	n,m = map(int, input().split(" ")) 
	dp = []
	vis = []

	for _ in range(n):
		s = input()
		dp.append(list(s))
		vis.append([False]*m)


	# start
	if not go(0,0):
		print(0)
	elif not go(0,0):
		print(1)
	else:
		print(2)







