(n,m)=map(int,input().split())
a=input()
if(a==('9'*n)):
    print(n+1)
    print('1'*(n+1))
else:
    ind=-1
    for i in range(0,n-m):
        if(i!='9'):
            ind=i
    c=[x for x in a]
    c[ind]=str(int(c[ind])+1)
    for i in range(ind+1,n-m):
        c[i]='0'
    for i in range(0,n-m):
        c[i+m]=c[i]
    print(n)
    print(''.join(c)[:n])
