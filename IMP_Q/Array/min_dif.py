def go(a1,a2):
    a1.sort()
    a2.sort()
    fst,scd=0,0
    dif=abs(a2[scd]-a1[fst])
    while (fst<len(a1)) and (scd<(len(a2))):
        dif=min(dif,abs(a2[scd]-a1[fst]))
        if(a1[fst]>a2[scd]):scd+=1
        else:fst+=1
    print(dif)

go([-1, 5, 10, 20, 28, 3], [26, 134, 135, 15, 17])