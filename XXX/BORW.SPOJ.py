y=[-1]*100001
def go(l,n,ind):
    if(y[n]!=-1): return y[n]
    elif(n==0):y[n]=1
    elif(n<0):y[n]= 0
    elif(ind==len(l)):y[n]= 0
    else:
        if(go(l,n-l[ind],ind+1) or go(l,n,ind+1)):
            y[n]=1
        else:
            y[n]=0
    return y[n]
n,m=map(int,input().split())
l=list(map(int,input().split()))
for _ in range(m):
    l1,r=map(int,input().split())
    count=0
    for i in range(l1,r+1):
        if(go(l,i,0)):
            count+=1
    print(count)

