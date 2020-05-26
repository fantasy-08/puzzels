dp=[[-1]*10000]*10000
num,m=0,0
def go(n,i):
    if(i==0):
        if(num<int(n)):return 1
        return 0
    if(dp[int(n)][i]!=-1): return dp[int(n)][i]
    b=0
    if(int(m)%2==0 and i%2==0) or (int(m)%2==1 and i%2==1) :
        if(n[3]=='9'):
            a1=n[:3]+'0'
            b=b or go(a1,i-1)
        else:
            a1=n[:3]+str(int(n[3])+1)
            b=b or go(a1,i-1)
        if(n[2]=='9'):
            a1=n[:2]+'0'+n[3]
            b=b or go(a1,i-1)
        else:
            a1=n[:2]+str(int(n[2])+1)+n[3]
            b=b or go(a1,i-1)
        if(n[3]=='9'):
            a1=n[:1]+'0'+n[2:]
            b=b or go(a1,i-1)
        else:
            a1=n[:1]+str(int(n[3])+1)+n[2:]
            b=b or go(a1,i-1)
        if(n[3]=='9'):
            a1='0'+n[1:]
            b=b or go(a1,i-1)
        else:
            a1=str(int(n[0])+1)+n[1:]
            b=b or go(a1,i-1)
    else:
        if(n[3]=='9'):
            a1=n[:3]+'0'
            b=b and go(a1,i-1)
        else:
            a1=n[:3]+str(int(n[3])+1)
            b=b and go(a1,i-1)
        if(n[2]=='9'):
            a1=n[:2]+'0'+n[3]
            b=b and go(a1,i-1)
        else:
            a1=n[:2]+str(int(n[2])+1)+n[3]
            b=b and go(a1,i-1)
        if(n[3]=='9'):
            a1=n[:1]+'0'+n[2:]
            b=b and go(a1,i-1)
        else:
            a1=n[:1]+str(int(n[3])+1)+n[2:]
            b=b and go(a1,i-1)
        if(n[3]=='9'):
            a1='0'+n[1:]
            b=b and go(a1,i-1)
        else:
            a1=str(int(n[0])+1)+n[1:]
            b=b and go(a1,i-1)
    dp[int(n)][i]=b
    return b
for _ in range(int(input())):
    num=input()
    m=num[5:]
    num=num[:4]
    if(go(num,int(m))):
        print('Ada')
    else:
        print('Vinit')