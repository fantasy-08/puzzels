def max_sum(arr):
    n=len(arr)
    sum_t=[0]*n
    for i in range(n):
        sum_t[i]=arr[i]
    size_t=[1]*n
    prev=[None]*n
    for j in range(1,n):
        for i in range(0,j):
            if(arr[j]>arr[i]) and ((sum_t[i]+arr[j])>sum_t[j]):
                size_t[j]=max(size_t[j],size_t[i]+1)
                sum_t[j]=max(sum_t[j],sum_t[i]+arr[j])
                prev[j]=i
    x=max(sum_t)
    ind=sum_t.index(x)
    print('size-->',size_t[ind])
    temp=prev[ind]
    ans=[arr[ind]]
    while temp!=None:
        ans.append(arr[temp])
        temp=prev[temp]
    print(ans[::-1],x)
max_sum([8,12,2,3,15,5,7])
max_sum([10,70,20,30,50,11,30])


