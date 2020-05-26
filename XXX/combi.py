dp=[-1]*600000
def go(s,ind,n):
    if(ind>=n or s[ind]=='0'):return 0
    if(ind==n-2):
        if(int(s[n-2:])<27): return 2
        else: return 1
    if(ind==n-1): return 1
    
    if(dp[ind]!=-1):
        return dp[ind]
    if int(s[ind:ind+2])>27:
        aa= go(s,ind+1,n)
    else:
        aa= (go(s,ind+1,n))+go(s,ind+2,n)
    dp[ind]=aa
    return dp[ind]
a=input()
while a!='0':
    dp=[-1]*600000
    print(go(a,0,len(a)))
    a=input()
