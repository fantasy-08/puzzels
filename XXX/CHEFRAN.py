#35 marks
def present(l1,l2):
    if(l1[0]<=l2[1] and l1[1]>=l2[0])or(l2[1]<=l1[0] and l2[1]>=l1[0]):
        return 1
    else:
        return 0
#print(present([1,4],[2,6]))
test=int(input())
for _ in range(test):
    n=int(input())
    l1=[]
    for i in range(n):
        l2=list(map(int,input().split()))
        l1.append(l2)
    l1.sort()
    i,j=0,n-1
    ans=1e7
    flag=0
    lower,upper=-1,-1
    for i in range(0,n-1):
        s1,s2=[],[]
        for j in range(n-1,i,-1):
            if(present(l1[i],l1[j])==0):
                flag=1
                lower=i
                upper=j
                s1.append(l1[lower])
                s2.append(l1[upper])
                for i in range(0,n):
                    if(i!=lower and i!=upper):
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
                    if(ans>(n-len(s1)-len(s2))):
                        ans=n-len(s1)-len(s2)
                    break
    if(flag==0):print(-1)
    else:
        print(ans)
                


