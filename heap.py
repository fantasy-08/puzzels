n=int(input())
def go(i):
    if(i==n):return 1
    if(i>n):return 0
    return go(i+1)+go(i+2)
print(go(0))