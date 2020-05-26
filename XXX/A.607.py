n,m=map(int,input().split())
l=[]
a=list(map(int,input.split()))
b=list(map(int,input.split()))
a.sort()
b.sort()
for i in a:
    l.append(b[0]-a[i])
