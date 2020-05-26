for _ in range(int(input())):
    c,n=map(int,input().split())
    temp1=int(c/n)*n
    x=int((c-int(n/2)+n)/n)
    temp2=(x*int(n/2))+((x-1)*(n-int(n/2)))
    print(max(temp1,temp2))
