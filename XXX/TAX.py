def tax(n):
    sum=0
    if(n<=250000):
        return 0
    if(n>500000):
        sum+=0.05*(500000-250000)
    else:
        return sum+(n-250000)*0.05
    if(n>750000):
        sum+=0.1*(750000-500000)
    else:
        return sum+(n-500000)*0.1
    if(n>1000000):
        sum+=0.15*(1000000-750000)
    else:
        return sum+(n-750000)*0.1
    if(n>1250000):
        sum+=0.2*(1250000-1000000)
    else:
        return sum+(n-1000000)*0.2
    if(n>1500000):
        sum+=0.25*(1500000-1250000)
    else:
        return sum+(n-1250000)*0.25
    return sum+(n-1500000)*0.30
for _ in range(int(input())):
    income=int(input())
    print(income-int(tax(income)))