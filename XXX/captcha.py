dp=[-1]*200000002
def ff(n):
    a=bin(n)[2:][::-1]
    for i in range(0,len(a)):
        if(a[i]=='1'):
            return i+1
for i in range(0,1001,2):
    dp[i]=ff(i)
print(dp[:1001:22])