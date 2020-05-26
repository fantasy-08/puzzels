def go(a,b):
    x=0
    for i in range(len(b)):
        if(b[i]==a[x]):x+=1
    return x

for _ in range(int(input())):
    a=input()
    b=input()
    z=[0]*26
    flag=0
    l=[]
    for i in range(len(a)):
        z[ord(a[i])-97]+=1
    for i in range(len(b)):
        if z[ord(a[i])-97]==0:
            flag=1
        l.append(b[i])
    if(flag):
        print(-1)
    count=0
    while(len(l)!=0):
        temp=go(l,a)
        if(temp==0):
            print(-1)
            break
        count+=1
        l=l[temp+1:]
    print(count)


    
    
