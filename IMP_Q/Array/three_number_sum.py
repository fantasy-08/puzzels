def sol(arr,ans):
    arr.sort()
    triplets=[]
    for i in range(len(arr)-2):
        right=len(arr)-1
        left=i+1
        while left<right:
            sum=arr[i]+arr[left]+arr[right]
            if(sum==ans):
                triplets.append([arr[i],arr[right],arr[left]])
                left+=1
                right-=1
            elif sum>ans:
                right-=1
            else: 
                left+=1
    print( triplets )
sol([12, 3, 1, 2, -6, 5, -8, 6], 0)
                
