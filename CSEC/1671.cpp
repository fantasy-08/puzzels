
// Problem : Shortest Routes I
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1671
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
// #include <bits/stdc++.h>
// #define FOR(i,n) for(int i=0;i<n;i++)
// #define FORR(i,n) for(int i=n;i>=0;i--)
// #define pb push_back
// #define vlli vector<int>
// #define slli set<int>
// #define mlli map<int,int>
// #define int long long int 
// #define test int tt1234; cin>>tt1234;while(tt1234--)
// #define endl "\n"
// #define all(zz) zz.begin(),zz.end()
// #define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// #define error(x) cerr << #x <<" is " << x << endl;
// #define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
// #define fint fast;test
// #define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
// #define input(a,n) int n;cin>>n; SI(a,n)
// #define set(a,x) memset(a,x,sizeof(a))
// #define L(x)	((x)<<1)
// #define R(x)	(((x)<<1)+1)
// #define ft first
// #define se second
// #define MOD 1000000007
// using namespace std;
// 
// void solve(){
	// int n,m;
	// cin>>n>>m;
	// map<pair<int,int>,int>cost;
	// vector<int>adj[n+1];
	// FOR(i,m)
	// {
		// int a,b,c;
		// cin>>a>>b>>c;
		// if(cost.find({a,b})!=cost.end())
		// {
			// cost[{a,b}]=min(cost[{a,b}],c);
			// continue;
		// }
		// adj[a].pb(b);
		// cost[{a,b}]=c;		
	// }
	// vector<int>dist(n+1,INT_MAX);
	// set<pair<int,int>>s;
	// s.insert({0,1});
	// dist[1]=0;
	// while(!s.empty())
	// {
		// auto C=*(s.begin());
		// s.erase(s.begin());
		// int node=C.se;
		// for(auto child:adj[node])
		// {
			// int weight=cost[{node,child}];
			// if(dist[child]>(dist[node]+weight))
			// {
				// if(dist[child]!=INT_MAX)
					// s.erase(s.find({dist[child],child}));
				// int Cost=dist[node]+weight;
				// dist[child]=Cost;
				// s.insert({Cost,child});
			// }
		// }
	// }
	// rep(i,1,n+1)cout<<dist[i]<<" ";
	// return;	
// }
// 
// 
// int32_t main() {
    // // fint{
    	// fast;
    	// solve();
    // // }
    // return 0;
// }
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define endl '\n'

const int maxn = 100000;
const long inf = 100000000000007;
int n, m;
long dist[maxn];
vector<pair<long, long>> graph[maxn];

void dijkstra(){
	for(int i = 0; i < n; i++) dist[i] = inf;
	
	priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;
	pq.push(make_pair(0, 0));
	dist[0] = 0;
	
	while(!pq.empty()){
		long c = pq.top().second, d = pq.top().first;
		pq.pop();
		
		if(dist[c] != d) continue;
		
		for(int i = 0; i < graph[c].size(); i++){
			int nc = graph[c][i].first, nd = graph[c][i].second;
			
			if(d + nd < dist[nc]){
				dist[nc] = d + nd;
				pq.push(make_pair(d + nd, nc));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		long a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		
		graph[a].push_back(make_pair(b, c));
	}
	
	dijkstra();
	
	cout << dist[0];
	for(int i = 1; i < n; i++) cout << " " << dist[i];
	cout << endl;

	return 0;
}
