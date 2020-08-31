#include<bits/stdc++.h>
#define int long long int
using namespace std;
int par[100005],size[100005];
void initialize( int Arr[ ],int size[], int N)
{
    for(int i = 0;i<N;i++)
	{
		Arr[ i ] = i ;
		size[ i ] = 1;
	}
}
int root (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
	    Arr[ i ] = Arr[ Arr[ i ] ] ; 
		i = Arr[ i ]; 
	}
	return i;
}
void union1(int Arr[ ],int size[ ],int A,int B)
{
    int root_A = root(Arr,A);
    int root_B = root(Arr,B);
    if(size[root_A] < size[root_B ])
    {
		Arr[ root_A ] = Arr[root_B];
		size[root_B] += size[root_A];
	}
    else
    {
		Arr[ root_B ] = Arr[root_A];
		size[root_A] += size[root_B];
	}

}
int32_t main()
{
	int n,m;
	cin>>n>>m;
	initialize(par,size,n);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		union1(par,size,u,v);
	}
	map<int,vector<int>>Par;
	vector<int>uni;
	for(int i=1;i<=n;i++)
	{
		int P=root(par,i);
		Par[P].push_back(i);
		if(Par[P].size()==1)
		{
			uni.push_back(P);
		}
	}	
	vector<int>arr(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	int ans=0;
	for(int X=0;X<uni.size();X++)
	{
		int temp=0;
		vector<int>tempA;
		tempA=Par[uni[X]];
		for(int i=0;i<tempA.size();i++)
		{
			temp+=arr[tempA[i]];
		}
		ans=max(ans,temp);
	}
	cout<<ans<<endl;
}