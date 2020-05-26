ch=dict()
m,n=0,0
MOD=1000000007
def ans(i,j,count):
    if((i==n-1) and (count&1)):
        if(j>=0 and j<=m-1):
            
            return 1
        else:
            return 0
    elif(i==n-1): return 0
    elif((i>=n) or (j>=m)) :return 0
    elif((i<0) or (j<0)) :return 0 
    count&=1

    if([i,j,count] in ch) :return ch[i][j][count]
    if([i,j,not count] in ch) :return 0
    ch[i][j][count]=(ans(i+2,j+1,count+1)%MOD)+(ans(i+1,j+2,count+1)%MOD)+(ans(i+2,j-1,count+1)%MOD)+(ans(i+1,j-2,count+1)%MOD)
    return ch[i][j][count]%MOD
n,m=map(int,input().split())
temp=0
for i in range(1,m,2):
	    temp+=(ans(0,i,0)%MOD)
print(temp%MOD)