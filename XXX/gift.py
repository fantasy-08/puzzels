dp=[-2]*1000000
def go(val,weight):
    if weight<=0:
        return 0
    if(dp[weight]!=-2):
        return dp[weight]
    ans=1e7
    for i in range(len(val)):
        if (val[i]!=-1) and ((weight-i-1)>=0) :
            ans=min(ans,val[i]+go(val,weight-i-1))
        else:break
    if ans==1e7:
        ans=-1
    dp[weight]=ans
    return dp[weight]

for _ in range(int(input())):
    (a,b)=(map(int,input().split()))
    arr=list(map(int,input().split()))
    print(go(arr,b))
    
	