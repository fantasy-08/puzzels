def present(l1,l2):
    #l2 is in l1 or not
    if(l2[0]<=l1[1]):
        return 1
    else:
        return 0
test=int(input())
for _ in range(test):
    n=int(input())
    l1=[]
    for i in range(n):
        l2=list(map(int,input().split()))
        l1.append(l2)
    l1.sort()
    i,j=0,n-1
    s1,s2=[],[]
    flag=0
    if(l1[0][1]<l1[j][0]):
        flag=1
        i+=1
    if(flag):
        s1.append(l1[0])
        s2.append(l1[n-1])
        while(i<j):
            c1,c2=0,0
            for cc in s2:
                if(present(cc,l1[i])):
                    c2=1
                    break
            for cc in s1:
                if(present(cc,l1[i])):
                    c1=1
                    break
            if(c2 and c1):
                pass
            elif(c2):
                s2.append(l1[i])
            else:
                s1.append(l1[i])
            i+=1
        ans=n-(len(s1)+len(s2))
        print(ans)
    else:
        print(-1)
