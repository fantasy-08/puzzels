for _ in range(int(input())):
    a,b,c=map(int,input().split())
    l=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    if(max(l)>max(l2)):
        print("YES")
    else:
        print("NO")