class Solution:
    def compareVersion(self, A: str, B: str) -> int:
        a=list(map(int,A.split('.')))
        b=list(map(int,B.split('.')))
        while(len(a) and a[-1]==0):a.pop()
        while(len(b) and b[-1]==0):b.pop()
        print(a,b)
        if a==b:return 0
        for i in range(int(min(len(a),len(b)))):
            if(a[i]!=b[i]):
                if(a[i]>b[i]):return 1
                return -1
        if(len(a)>len(b)):return 1
        return -1