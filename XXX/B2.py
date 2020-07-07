hash=dict()
def pick_work(l):
    search=tuple(l)
    if(search in hash):
        return hash[search]
    ans=[]
    maxx=600
    for i in range(len(l)-1):
        if(l[i]==l[i+1]):
            ans.append(i)
    if(len(ans)==0):return len(l)
    for index in ans:
        temp=[x for x in l]
        temp[index]+=1
        temp.pop(index+1)
        maxx=min(maxx,pick_work(temp))
    hash[search]=maxx
    return maxx
n=int(input())
arr=list(map(int,input().split()))
print(pick_work(arr))