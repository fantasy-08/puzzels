def maxaa(l,vis):
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
            ans=max(ans,score(l[ii],l[i])+maxaa(l,vis))
            vis[ii],vis[i]=0,0
    return ans
def score(a,b):
    i=0
    ans,ans2=0,0
    while i<min(len(a),len(b)):
        if(a[i]==b[i]): ans+=1
        else: break
        i+=1
    a2=a[::-1]
    b2=b[::-1]
    i=0
    while i<min(len(a2),len(b2)):
        if(a2[i]==b2[i]): ans2+=1
        else: break
        i+=1
    return min(ans,ans2)**2
for _ in range(int(input())):
    n=int(input())
    l=[]
    l2=[]
    count=[0]*26
    #visited=[0]*n
    for _ in range(n):
        temp=input()
        l.append(temp)
        count[ord(temp[0])-97]+=1
        l2.append(temp[::-1])
    l.sort()
    prev,ans=0,0
    for i in range(26):
        if(count[i]!=0):
            y=l[prev:prev+count[i]]
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


















    '''l2.sort()
    final_ans=0
    for i in range(0,n,2):
        if((i+1)<n):
            final_ans+=score(l[i],l[i+1])
        else: break
    final_ans2=0
    for i in range(0,n,2):
        if((i+1)<n):
            final_ans2+=score(l2[i],l2[i+1])
        else: break
    print(max(final_ans,final_ans2))
'''


