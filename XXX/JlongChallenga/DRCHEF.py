test = int(input())
while(test):
    n,x=map(int,input().split())
    a=list(map(int,input().split()))
    a.sort()
    if(x>=a[-1]):
        print(n)
    else:
        move,count,i=0,0,0
        tot=n
        while(i<n):
            if x>a[i]:
                temp=a[i]*2
                if(temp>=x):
                    tot-=1
                    i+=1
                    move+=1
                    x=temp
                else:i+=1
            else:
                move+=1
                x=x*2
        print(move+tot)
    test-=1