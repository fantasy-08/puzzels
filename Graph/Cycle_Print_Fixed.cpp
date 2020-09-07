#include<bits/stdc++.h>
using namespace std;
const int N=10;
vector<vector<int>>adj,Cycles;
vector<int>Mark,par,color;
int cycle_count=0;
void dfs(int node,int papa)
{
	if(color[node]==2)return ;
	if(color[node]==0){
		color[node]=1;
		par[node]=papa;
		for(auto child:adj[node]){
			if(child!=papa)
				dfs(child,node);
		}
		color[node]=2;
		return ;
	}
	vector<int>Cycle_Local;
	cycle_count++;
	int current = papa;
	// Mark[current]=cycle_count;
	Cycle_Local.push_back(current);
	while(current!=node)
	{
		current=par[current];
		// Mark[current]=cycle_count;	
		Cycle_Local.push_back(current);
	}	
	Cycles.push_back(Cycle_Local);
	return ;
}
void initialize()
{
	color.resize(N+1),par.resize(N+1);
	adj.resize(N+1,vector<int>());
}
int main()
{
	initialize();
	adj[1].push_back(2),adj[2].push_back(1);
	adj[2].push_back(3),adj[3].push_back(2);
	adj[3].push_back(5),adj[5].push_back(3);
	adj[2].push_back(4),adj[4].push_back(2);
	adj[5].push_back(6),adj[6].push_back(5);
	adj[4].push_back(5),adj[5].push_back(4);
	adj[3].push_back(6),adj[6].push_back(3);
	dfs(1,-1);	
	/*map<int,vector<int>>Ans;
	for(int i=1;i<=N;i++){
		if(Mark[i]!=0){
			Ans[Mark[i]].push_back(i);
		}
	}
	*/
	for(auto v:Cycles){
		cout<<"Cycle -> ";
		for(auto node:v){
			cout<<node<<" ";
		}
		cout<<endl;
	}
}
/*
GRAPH
1----2----3------
     |    |     |
     4----5-----6
*/