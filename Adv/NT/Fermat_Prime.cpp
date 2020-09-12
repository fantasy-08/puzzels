int mulmod(int a, int b,int c){
    lli x = 0,y=a%c;
    while(b > 0){
    if(b%2 == 1){
        x = (x+y)%c;
    }
    y = (y*2LL)%c;
    b /= 2;
    }
    return x%c;
}
 
int binPower(int a , int n , int mod)
{
	int res = 1;
 
	while(n)
	{
		if(n & 1)
		res = mulmod(res , a , mod);
 
		n >>= 1;
		a = mulmod(a , a , mod);
	}
 
	return res % mod;
}
 
bool isPrime(int n , int iterations = 5)
{
	if(n <= 4)
	return n == 2 || n == 3;
 
	for(int i=1;i<=iterations;i++)
	{
		int a = 2 + rand() % (n - 3);
		int res = binPower(a , n - 1 , n);
 
		if(res != 1) return false;
	}
 
	return true;
}
