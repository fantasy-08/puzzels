while len(que)!=0:
        x=(que.pop())
        ans.append(x)
        for i in arr:
            if(len(x)>0):
                if(i in x):
                    continue
                else:
                    temp=x.append(i)
                    que.append(temp)
            else:
                temp=x.append(i)
                que.append(temp)