int policeAndThief(char arr[],int n,int k)
{
	int res=0,i=0;
	int thief[n];
	int police[n];
	int N1=0,N2=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]=='P')
		{
			police[N1++]=i;
		}
		else
		{
			thief[N2++]=i;
		}
	}
	int l=0,r=0,caught_theif=0;
	while(l<N2 && r<N1)
	{
		if(abs(thief[l]-police[r])<=k)
		{
			caught_theif++;
			l++,r++;
		}
		else if(theif[l]<police[r])
		{
			l++;
		}
		else
		{
			r++;
		}
	}
	return caught_theif;
}