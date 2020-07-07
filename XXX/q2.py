def com(a):
    b=bin(a)[2:]
    s=''
    for i in b:
        if i=='0':s+='1'
        else:s+='0'
    return (int(s,2))
for i in range(int(input())):
    n=int(input())
    flag=0
    while True:
        y=com(n)
        if(y==0):break
        n-=y
        flag=not flag
    if(flag):print('Jatin')
    else:print('Pranshu')
