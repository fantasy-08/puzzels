int updateTimes(vector<int>A,vector<int>B)
{
	int ans=0;
	int max_equal=0;
	for(int i=0;i<A.size();i++)
	{
		if(A[i]==B[i])
		{
			if(A[i]>max_equal)
			{
				max_equal=A[i];
				ans++;
			}
		}
	}
	return ans;
}
vector<int> CountingBits(int n)
{
	vector<int>ans;
	int cnt=0;
	int st=0;
	for(int i=31;i>=0;i--)	
	{
		if(n&(1<<i))
		{
			st=i;
			break;
		}
	}
	int index=1;
	for(int i=st;i>=0;i--)
	{
		if(n&(1<<i))
		{
			ans.push_back(index);
		}
		index++;
	}
	ans.insert(ans.begin(),(int)ans.size());
	return ans;	
}