#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<bool>vis;
vector<int>P;
int n,m;
int size=0;
int dfs(int node)
{
	vis[node]=true;
	size++;
	int temp=0;
	for(int i=0;i<adj[node].size();i++)
	{
		int child=adj[node][i];
		if(!vis[child])
		{
			temp+=dfs(child);
		}
	}
	return temp+P[node];
}
int32_t main()
{
	cin>>n>>m;
	adj.resize(n+1,vector<int>());
	vis.resize(n+1);
	P.resize(n+1);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		cin>>P[i];
	
	int ansP=0,ansS=0;
	//Search
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==true)continue;
		size=0;
		int tempA=dfs(i);
		if(tempA>ansP)
		{
			ansP=tempA;
			ansS=size;
		}
		else if(tempA==ansP)
		{
			ansS=max(ansS,size);
		}
	}
	cout<<ansS;
}