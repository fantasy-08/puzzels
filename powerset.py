def powerset(arr):
    que=[[]]
    for i in arr:
        ee=len(que)
        for j in range(ee):
            y=que[j]
            que.append(y+[i])
    print(que)
powerset([2,3,5])
