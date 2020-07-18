class Solution {
public:
    double callpos(double x, int n){
    if(n==1)
        return x;
    double res=1;
    res=callpos(x,n/2);
    if(n%2==0)
        return res*res;
    else
        return x*res*res;
    }
    double myPow(double x, int n){
        long inp=n;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if(n==-1)
            return 1/x;
        if(inp>1)
            return x*callpos(x,inp-1);
        else 
            return 1/(x*callpos(x,-inp-1));
    }
};