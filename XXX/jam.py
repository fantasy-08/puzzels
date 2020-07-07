def make_path(arr,s):
    i1,j1=0,0
    for i in range(len(s)):
        if(s[i]=='E'):
            arr[i1][j1+1]=[i1,j1]
            i1,j1=i1,j1+1
        else:
            arr[i1+1][j1]=[i1,j1]
            i1,j1=i1+1,j1
    return arr
def find_new_path(arr,n):
    ans=''
    i,j=0,0
    while i!=(n-1) or j!=(n-1):
        # if(i==n-1):
        #     j+=1
        #     ans+='E'
        #     continue
        # if(j==n-1):
        #     i+=1
        #     ans+='S'
        #     continue
        if(arr[i][j+1]==0 and j!=n-1):
            ans+='E'
            j+=1
        elif(arr[i+1][j]==0 and i!=n-1) :
            ans+='S'
            i+=1
        else:
            if(arr[i+1][j]!=[i,j]):
                ans+='S'
                i+=1
            else:
                ans+='E'
                j+=1

    return ans



def solve():
    n=int(input())
    arr=[[0]*n for x in range(n)]
    s=input()
    arr=make_path(arr,s)
    return (find_new_path(arr,n))
    

test=int(input())
for xxx in range(test):
    myans=solve()
    print('Case #'+str(xxx)+': '+myans)