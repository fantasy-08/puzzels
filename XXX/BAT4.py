def go(arr,n):
    A =[0]*n
    dp=[A]*n
    dp[0]=arr[0]
    for i in range(1,n):
        dp[i][0]=arr[i][0]
    for i in range(1,n):
        for j in range(1,n):
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])
    return dp[n-1][n-1]
for _ in range(int(input())):
    a,t=map(int,input().split())
    l=list()
    for i in range(a):
        l.append(list(map(int,input().split())))
    aa=go(l,a)
    print('YES :',aa,t-aa)
