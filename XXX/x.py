for _ in range(int(input())):
    n=int(input())
    s=input()
    ans=''
    count=0
    for i in s:
        if(count==2):
            break
        if(int(i)%2==1):
            ans+=i
            count+=1
    if(count==2):print(int(ans))
    else:
        print(-1)
    