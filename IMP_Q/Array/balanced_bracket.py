def chek_balanced(arr):
    op=[]
    for i in range(len(arr)):
        if arr[i]=='(' or arr[i]=='{' or arr[i]=='[':
            op.append(arr[i])
        else:
            x=op[len(op)-1]
            if(arr[i]==']' and x=='['):op.pop()
            elif(arr[i]==')' and x=='('):op.pop()
            elif(x=='{'):op.pop()
            else: return False
    if(op==[]): return True
    return False
if(chek_balanced('([])(){}(())()()')):print(1)
else:print(0)