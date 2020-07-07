
// Problem : Chef and Digit Jumps
// Contest : CodeChef - DSA Learning Series - Contest 8
// URL : https://www.codechef.com/LRNDSA08/problems/DIGJUMP
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;

void solve(){
	string s;
	cin>>s;
	map<int,slli>adj;
	FOR(i,s.size()){
		int val=s[i]-'0';
		adj[val].insert(i);
	}
	queue<pair<int,int>>q;
	q.push({0,0});
	vlli dis(s.size(),INT_MAX);
	dis[0]=0;
	vector<bool>vis(10,false);
	adj[s[0]-'0'].erase(0);
	while(q.size())
	{
		int node=q.front().ft;
	// error(node);
		int weight=q.front().se;
		q.pop();
		// error(node);
		if(node-1>=0 && dis[node-1]==INT_MAX){
			q.push({node-1,weight+1});
			dis[node-1]=weight+1;
			if(adj[s[node-1]-'0'].find(node-1)!=adj[s[node-1]-'0'].end())
			adj[s[node-1]-'0'].erase(node-1);
		}
		// error(node);
		if(node+1<s.size() && dis[node+1]==INT_MAX){
			q.push({node+1,weight+1});
			dis[node+1]=weight+1;
			if(adj[s[node+1]-'0'].find(node+1)!=adj[s[node+1]-'0'].end())
			adj[s[node+1]-'0'].erase(node+1);
		}		
		// error(node);
		// if(vis[node])continue;
		vlli temp;
		for(auto child:adj[s[node]-'0']){
			if(dis[child]==INT_MAX){
				q.push({child,weight+1});
				dis[child]=weight+1;
				temp.pb(child);
				// if(adj[s[child]-'0'].find(child)!=adj[s[child]-'0'].end())
				// adj[s[child]-'0'].erase(child);
			}
		}		
		for(auto child:temp){
			adj[s[node]-'0'].erase(child);
		}	
		// vis[node]=true;
	}
	cout<<dis[s.size()-1]<<endl;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
