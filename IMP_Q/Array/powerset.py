def all_per(l):
    # y=set()
    q=[[]]
    for i in l:
        x=len(q)
        for v in range(x):
            q.append(q[v]+[i])
    print(q)
all_per([1,2,3])
