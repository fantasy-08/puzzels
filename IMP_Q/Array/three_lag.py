arr= [10, 5, 9, 10, 12]
def lar(arr):
    ans=[None,None,None] #a< b< c
    for i in arr:
        if(None in ans):
            for i1 in range(2,-1,-1):
                if(ans[i1]==None):
                    ans[i1]=i
                    break
        else:
            if(i>=ans[2]):
                ans[0]=ans[1]
                ans[1]=ans[2]
                ans[2]=i
            elif(i>=ans[1]):
                ans[0]=ans[1]
                ans[1]=i
            elif(i>=ans[0]):
                ans[0]=i
            else: pass
    return ans
print(lar(arr))