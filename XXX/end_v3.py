scr=[]
def maxaa(l,vis):
    global scr
    ans=0
    ii=-1
    for i in range(len(l)):
        if(vis[i]==0):
            ii=i
            break
    if(ii==-1):return 0
    for i in range(0,len(l)):
        if(i!=ii and vis[i]==0):
            vis[ii],vis[i]=1,1
            ans=max(ans,scr[ii][i]+maxaa(l,vis))
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
        if(count[i]>1):
            y=l[prev:prev+count[i]]
            zzz=len(y)
            #lets create 2D Score array
            scr = [[0 for i in range(zzz)] for j in range(zzz)] 
            for i1 in range(zzz):
                for j1 in range(zzz):
                    if(i1!=j1):
                        scr[i1][j1]=score(y[i1],y[j1])
            #scr array made
            i,countl=0,0
            while i<zzz:
                if(i<=zzz-3) :
                    if scr[i][i+1]>scr[i+1][i+2]:
                        ans+=scr[i][i+1]
                        countl+=2
                        i+=2
                    else:
                        i+=1
                else:
                    break
                ans+=int((zzz-countl)/2)
    print(ans)
