#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100001];
vector<bool>vis;
set<int>P;
int n,m;
int Ans;
int dfs(int node)
{
	vis[node]=true;
	int ans=0;
	if(P.count(node))ans++;
	int K=ans;
	vector<int>val;
	for(int i=0;i<adj[node].size();i++)
	{
		int child=adj[node][i];
		if(!vis[child])
		{
			val.push_back(dfs(child));
		}
	}
	sort(val.rbegin(),val.rend());
	for(int i=0;i<min((int)val.size(),2);i++)
		ans+=val[i];
	Ans=max(Ans,ans);
	if(val.size()==0)
		return ans;
	else 
		return K+val[0];
}
int32_t main()
{
	cin>>n>>m;
	vis.resize(n+1);
	for(int i=1;i<=m;i++)
	{
		int t;
		cin>>t;
		P.insert(t);
	}
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	Ans=0;
	dfs(1);	
	cout<<Ans;
}