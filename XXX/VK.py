n=int(input())
s={input()}
a=0
while all("VK"in q for q in s):a+=1;s={a[:i]+a[i+1]+a[i]+a[i+2:]for a in s for i in range(len(a)-1)}
print(a)