def my(a,b):
    c=''
    for i in range(len(a)):
        if(a[i]==b[i]):
            c+=a[i]
        else:
            m=sort(a[i]+b[i])
            
    return c
a,b=map(int,input().split())
ans=0
l=list()
for _ in range(a):
    l.append(input())
for i in range(a-2):
    for j in range(i+1,a-1):
        yy=my(l[i],l[j])
        print(l[i],l[j],yy)
        '''for k in range(j+1,a):
            if(l[k]==yy):ans+=1'''
print(ans)
