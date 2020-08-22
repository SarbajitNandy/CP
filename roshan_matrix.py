def check(sl):
    s = []
    for i in range(len(sl)):
        if sl[i]=='*':
            s.append(i)
    return s

n,m = list(map(int,input().split(" ")))
l = []
dp = {}
res = [ 0 for i in range(max(n,m)+1)]

for i in range(n):
    sl = list(input())
    l.append(sl)
    dp[i] = check(sl)
    res[1]+= len(dp[i])

print(res[1])

k_len = int(input())
k_val = []

for i in range(k_len):
    k_val.append(int(input()))

mx = min(max(k_val),min(n,m))

for k in range(2,mx+1) :
    count=0
    for i in range(n-k+1):
        # print(dp[i])
        rem = []
        for j in dp[i]:
            if j+1 in dp[i] and j+1 in dp[i+1] and j in dp[i+1]:
                count+=1
                # print("s:  j",j)
            else:
                rem.append(j)
                # print('f: j',j)
        for j in rem:
            dp[i].remove(j)
    # print('such possibility for k={0} is {1}'.format(k,count))
    res[k]=count + res[k-1]


for i in k_val:
    if (i>mx):
        print(res[mx])
    else:
        print(res[i])

