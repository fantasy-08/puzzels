'''
// 1 0 0 1 0
// 1 0 1 0 0
// 0 0 1 0 1
// 1 0 1 0 1
// 1 0 1 1 0

// 1 0 0 1 0
// 2 0 1 0 0
// 0 0 2 0 1
// 1 0 3 0 2
// 2 0 4 5 0'''
ans=[]
def val(arr):
    visited=[]
    for i in arr:
        x=[]
        for j in i:
            x.append(False)
        visited.append(x)
    for i in range(arr):
        for j in range(len(arr[i])):
            if(arr[i][j]==0):
                continue
            elif(visited[i][j]==True):
                continue
            else:
                traverse(i,j,visited,arr)

def traverse(ii,jj,visited,arr):
    que=[[ii,jj]]
    size=0
    while len(que):
        xx=que.pop()
        i=xx[0]
        j=xx[1]
        if(visited[i][j+1]==False and arr[i][j+1]==1):
            size+=1
            que.append([i,j+1])
            visited[i][j+1]=True
        if(visited[i+1][j]==False and arr[i+1][j]==1):
            size+=1
            visited[i+1][j]=True
            que.append([i+1,j])
        if(visited[i][j-1]==False and arr[i][j-1]==1):
            size+=1
            visited[i][j-1]=True
            que.append([i,j-1])
        if(visited[i-1][j]==False and arr[i-1][j]==1):
            size+=1
            visited[i-1][j]=True
            que.append([i-1,j])
    ans.append(size)
val([ [1, 0, 0, 1, 0], [1, 0, 1, 0, 0], [0, 0, 1, 0, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 0]])
        