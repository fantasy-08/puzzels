/*
Phi(n)=n*Sum((p-1)/p)
*/
//O(sqrt(n))
int phi(int n)
{
	int res=n;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			res*=(i-1);
			res/=i;
			while(n%i==0)n/=i;
		}
	}
	if(n>1)
	{
		res*=(n-1);
		res/=n;
	}
	return res;
}
//O(Nlog(log(N)))
int maxN=1e6+1;
int seive[1000001];
void PhiQ()
{
	FOR(i,maxN)seive[i]=i;
	rep(i,2,maxN+1)
	{
		if(seive[i]==i)
		{
			for(int j=i;j<=maxN;j+=i)
			{
				seive[j]*=(i-1);
				seive[j]/=i;
			}
		}
	}
}