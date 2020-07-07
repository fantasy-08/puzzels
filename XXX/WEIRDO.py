def whose(strin):
    vv,cc=0,0
    for i in strin:
        #print(i)
        if i=='a' or i=='e' or i=='i' or i=='o' or i=='u':
            vv+=1
        else:
            cc+=1
    if(vv>=cc):
        return 1
    else:
        return 0
test=int(input())
for _ in range(test):
    n=int(input())
    bob,kal=[],[]
    bobs,kals,k_bob,k_kal='','',0,0
    for _ in range(n):
        inpu=input()
        if(whose(inpu)==1):
            bob.append(inpu)
            bobs+=inpu
            k_bob+=1
        else:
            kal.append(inpu)
            kals+=inpu
            k_kal+=1
    hash_bob=[0]*26
    hash_kal=[0]*26
    uni_bob,uni_kal='',''
    for i in bobs:
        if(hash_bob[ord(i)-97]==0):uni_bob+=i
        hash_bob[ord(i)-97]+=1
    for i in kals:
        if(hash_kal[ord(i)-97]==0):uni_kal+=i
        hash_kal[ord(i)-97]+=1
    ans_bob,ans_kal=1,1
    #calculating for bob
    for i in uni_bob:
        count=0
        for word in bob:
            if i in word:
                count+=1
        ans_bob*=((count)/((hash_bob[ord(i)-97])**k_bob))
    for i in uni_kal:
        count=0
        for word in kal:
            if i in word:
                count+=1
        ans_kal*=((count)/((hash_kal[ord(i)-97])**k_kal))
    ans=ans_bob/ans_kal
    if(ans>10000000):print("Infinity")
    else:print(ans)
     