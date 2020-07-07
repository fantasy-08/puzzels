scr=[]
y=[]
def maxaa(vis):
    global scr
    global y
    ans=0
    ii=-1
    for i in range(len(y)):
        if(vis[i]==0):
            ii=i
            break
    if(ii==-1):return 0
    for i in range(0,len(y)):
        if(i!=ii and vis[i]==0):
            vis[ii],vis[i]=1,1
            ans=max(ans,scr[ii][i]+maxaa(vis))
            vis[ii],vis[i]=0,0
    return ans
def score(a,b):
    i=0
    ans,ans2=0,0
    while i<min(len(a),len(b)):
        if(a[i]==b[i]): ans+=1
        else: break
        i+=1
    if(a[len(a)-1]==b[len(b)-1]):
        a2=a[::-1]
        b2=b[::-1]
        i=1
        ans2=1
        while i<min(len(a2),len(b2)):
            if(a2[i]==b2[i]): ans2+=1
            else: break
            if(ans2>ans):break
            i+=1
    return min(ans,ans2)**2
for _ in range(int(input())):
    n=int(input())
    l=[]
    count=[0]*26
    for _ in range(n):
        temp=input()
        l.append(temp)
        count[ord(temp[0])-97]+=1
    l.sort()
    prev,ans=0,0
    for i in range(26):
        if(count[i]!=0):
            y=l[prev:prev+count[i]]
            zzz=len(y)
            #lets create 2D Score array
            scr = [[0 for i in range(zzz)] for j in range(zzz)] 
            for i1 in range(zzz):
                for j1 in range(zzz):
                    if(i1!=j1):
                        scr[i1][j1]=score(y[i1],y[j1])
            #scr array made
            prev+=count[i]
            visited=[0]*count[i]
            if count[i]%2==0:
                tt=(maxaa(y,visited))
            else:
                final=0
                for i in range(0,count[i]):
                    visited[i]=1
                    if(i>0):visited[i-1]=0
                    final=max(final,maxaa(y,visited))
                tt=(final)
            ans+=tt
    print(ans)
