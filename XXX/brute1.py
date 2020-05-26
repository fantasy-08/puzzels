for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    y=max(arr)
    flag=0
    for i in arr:
        if((y-i)%2==0):continue
        else: 
            flag=1
            break
    if(flag):print('NO')
    else:print('YES')