hash=dict()
def go(s,count):
    G=tuple(s)
    if((G,count) in hash): return hash[(G,count)]
    if(len(s)==1):return count
    maxx,flag=0,0
    if(s[0]-s[1]==1):
        l=s.copy()
        flag=1
        l.pop(0)
        maxx=max(maxx,go(l,count+1)) 
    if(s[len(s)-1]-s[len(s)-2]==1):
        l=s.copy()
        flag=1
        l.pop()
        maxx=max(maxx,go(l,count+1)) 
    for i in range(1,len(s)-1):
        if(s[i]!=0):
            if((s[i]-s[i+1]==1) or (s[i]-s[i-1]==1)):
                flag=1
                l=s.copy()
                l.pop(i)
                maxx=max(maxx,go(l,count+1))
    if(flag==0):
        hash[(G,count)]=count
        return count
    hash[(G,count)]=maxx
    return maxx
n=int(input())
l=input()
arr=[(ord(x)-97) for x in l]
print(go(arr,0))
