import math  
def perfect(x): 
  
    if(x==0 or x==1):return 0
    sr = math.sqrt(x) 
   
    # If square root is an integer 
    return ((sr - math.floor(sr)) == 0) 

def gcd(a,b): 
  
    if (a == 0): 
        return b 
    if (b == 0): 
        return a 

    if (a == b): 
        return a 

    if (a > b): 
        return gcd(a-b, b) 
    return gcd(a, b-a) 
  

def reduceFraction(x, y) : 
    if(x==0):print(0)
    else:
        d = gcd(x, y)    
        x = x // d 
        y = y // d 
    
        print(str(x)+'/'+str(y))

  

def printDivisors(n) : 
      
    N=0
    D=0
    i = 1
    l=[]
    y=[]
    while i <= math.sqrt(n): 
          
        if (n % i == 0) : 
 
            if (n / i == i) : 
                if(i%2==0):
                    D+=1
                    #l.append(i)
                    #print(i)
                    if(perfect(i) and i!=n):
                        N+=1
                       
            else : 
                D+=2
                if(i%2==0 and (n/i)%2==0):
                   


                    if(perfect(i)):
                        N+=1
                        #y.append(i)
                    if(perfect(n/i)):
                        N+=1
                        #y.append(n/i)
                elif(i%2==0):
                    if(perfect(i)):
                        N+=1
                elif((n/i)%2==0):
                    if(perfect(n/i)):
                        N+=1
                    
                #print i , n/i, 
        i = i + 1
    D=D-1
    if(perfect(n)):N-=1
    #print(y)
    
    return (N,D)
for _ in range(int(input())):
    x=int(input())
    (nn,dd)=printDivisors(x)
    reduceFraction(nn,dd)