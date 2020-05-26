import math
for _ in range(int(input())):
    n=int(input())
    goal=input()
    flag=0
    a,b=0,0
    for i in range(len(goal)):
        if(i%2==0):
            a+=int(goal[i])
        else:
            b+=int(goal[i])
        if(a>b and a>(b+math.ceil((2*n-i-1)/2))):
            print(i+1)
            flag=1
            break
        if(b>a and b>math.ceil((a+(2*n-i-1)/2))):
            
            print(i+1)
            flag=1
            break
    if(flag==0):
        print(2*n)

    