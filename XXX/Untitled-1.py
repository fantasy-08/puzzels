import sys
def dist(x,xx,y,yy):
    '''if x==xx and y==yy:return 0
    elif x==xx: return (yy-y)**2
    elif y=yy: (xx-x)**2'''
    return (xx-x)**2 + (yy-y)**2
test=int(input())
for _ in range(test):
    x,y=map(int,input().split(' '))
    a,b,c=map(int,input().split(' '))
    arr1=list(map(int,input().split(' ')))
    arr3=list(map(int,input().split(' ')))
    arr2=list(map(int,input().split(' ')))
    min1,min2,min12,min22=sys.maxsize,sys.maxsize,sys.maxsize,sys.maxsize
    for i in range(0,2*a,2):
        temp=dist(arr1[i],x,arr1[i+1],y)
        if(temp<min1):
            min1=temp
            ind1=i
    for i in range(0,2*b,2):
        temp=dist(arr2[i],arr1[ind1],arr2[i+1],arr1[ind1+1])
        if(temp<min12):
            min12=temp
            ind1=i
    ans1=min1**0.5 + min12**0.5
    min12=sys.maxsize
    for i in range(0,2*c,2):
        temp=dist(arr3[i],arr2[ind1],arr3[i+1],arr2[ind1+1])
        if(temp<min12):
            min12=temp
            ind2=i
    ans1+=min12**0.5
    for i in range(0,2*b,2):
        temp=dist(arr2[i],x,arr2[i+1],y)
        if(temp<min2):
            min2=temp
            ind2=i
    min22=sys.maxsize
    for i in range(0,2*a,2):
        temp=dist(arr1[i],arr2[ind2],arr1[i+1],arr2[ind2+1])
        if(temp<min22):
            min22=temp
            ind1=i
    ans2=min2**0.5+min22**0.5;
    min12=sys.maxsize
    for i in range(0,2*c,2):
        temp=dist(arr3[i],arr1[ind1],arr3[i+1],arr1[ind1+1])
        if(temp<min12):
            min12=temp
            ind2=i
    ans2+=min12**0.5;
    if(ans1>ans2):
        print(ans2)
    else:
        print(ans1)