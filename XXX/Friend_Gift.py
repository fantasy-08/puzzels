l=dict()
y=list()
arr=list(map(int,input().split()))
for i in range(len(arr)):
    l[arr[i]]=i
    if(arr[i]==0):y.append(arr[i])
l.sort()
y.sort()
print(l,y)