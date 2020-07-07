for _ in range(int(input())):
    n=int(input())
    store=dict()
    for _ in range(n):
        a,b=map(int,input().split())
        store[a]=b
    store.sort()
    print(store)