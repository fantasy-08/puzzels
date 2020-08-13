int Div(int n)
{
	if(n==1)return 1;
	int ans=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			int P=0;
			while(n%i==0)n/=i,P++;
			ans*=(P+1);
		}		
	}
	if(n>1)ans*=2;
	return ans;
}