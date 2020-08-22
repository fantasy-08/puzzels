/*
// Problem : A. Xor-tree
// Contest : Codeforces - Codeforces Round #245 (Div. 1)
// URL : https://codeforces.com/problemset/problem/429/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

There is something to learn from “propagating tree” problem, used in round #225. It’s how the special operation works. I’ll copy paste the explanation from there (with some modification, corresponding to the problem):

Let’s define level of a node the number of edges in the path from root to the node. Root (node 1) is at level 0, sons of root are at level 1, sons of sons of root are at level 2 and so on. Now suppose you want to do a special operation to a node x. What nodes from subtree of x will be flipped? Obviously, x will be first, being located at level L. Sons of x, located at level L + 1 will not be flipped. Sons of sons, located at level L + 2, will be flipped again. So, nodes from subtree of x located at levels L, L + 2, L + 4, ... will be flipped, and nodes located at levels L + 1, L + 3, L + 5 won’t be flipped. Let’s take those values of L modulo 2. All nodes having remainder L modulo 2 will be flipped, and nodes having reminder (L + 1) modulo 2 will not. In other words, for a fixed x, at a level L, let y a node from subtree of x, at level L2. If L and L2 have same parity, y will be flipped, otherwise it won’t. We’ll use this fact later. For now, let’s think what should be our first operation. Let’s consider some nodes {x1, x2, ..., xk} with property that x1 is son of x2, x2 is son of x3, ... xk-1 is son of xk and parity of levels of these nodes is the same. Suppose by now we fixed {x1, x2, ..., xk-1} (their current value is equal to their goal value), but xk is still not fixed. After some time, we’ll have to fix xk. Now, by doing this, all nodes {x1, x2, ..., xk-1} will get flipped and hence unfixed. We’ve done some useless operations, so our used strategy is not the one that gives minimal number of operations.

What we learn from this example? Suppose I want to currently fix a node X. There is no point to fix it now, unless all ancestors Y of X with property level(Y) = level(X) (mod 2) are fixed. But what if an ancestor Y of X is not fixed yet and level(Y) != level(X) (mod 2)? Can I fix node X now? The answer is yes, as future operations done on Y won’t affect X. But, by same logic, I can firstly fix Y and then fix X, because again operations done on Y won’t affect X. We get a nice property: there is no point to make an operation on a node X unless all ancestors of X are fixed.

How can we use this property? What should be the first operation? We know that node 1 is the root, hence it always won’t have any ancestor. All other nodes might have sometimes not fixed ancestors, but we know for sure, for beginning, node 1 won’t have any unfixed ancestor (because it won’t have any). So, for beginning we can start with node 1. More, suppose node 1 is unfixed. The only way to fix it is to make an operation on it. Since it’s unfixed and this is the only way to fix it, you’ll be obligated to do this operation. This means, in an optimal sequence of operations, you’ll be obligated to do this operation, too.

So, if node 1 was unfixed, we did an operation on it. If it was already fixed, we’re done with it. What are next nodes we know for sure that will have all ancestors fixed? Sons of 1, because they have only one ancestor (node 1), which we know it’s fixed. We can only fix them by doing operations of them (doing operations on node 1 / sons of them won’t affect them). Since eventually they have to be fixed and only way to be fixed is to do an operation on them, in an optimal sequence of operations, we’ll have to make operations on them. Let’s move on. What are next nodes that we know for sure all ancestors of them will be fixed? Sons of sons of 1. We can fix them by doing an operation of them, or by doing an operation on 1. But doing an operation on 1 isn’t helpful, because even if it fixes this node, it unfixes 1. Then, you’ll have to do one more operation on 1, which will unfix current node, so we do two useless operations. It turns out, the only way to fix them is to do an operation on them.

Generally, suppose all ancestors of node x are fixed. We get the current value of node x after the operations done on ancestors of x. If the current value is not the expected one, we’ll have to do an operation on node x (this is the only way to fix the node x). Now, after node x is fixed, we can process sons of it. This strategy guarantees minimal number of operations, because we do an operation only when we’re forced to do it.

This leads immediately to an O(N ^ 2) algorithm, by every time we need to do an operation to update it to nodes from its subtree. How to get O(N)? Suppose we are at node x and want to know its current value after operations done for its ancestors. Obviously, it is defined by initial value. If we know number of operations done so far by even levels for its ancestors, number of operations done so far by odd levels and current level, we can determine the current value. Suppose these values are (initial_value, odd_times, even_times, level). We observe that 2 operations cancel each other, so we can take this number modulo 2. If level mod 2 = 0, then only even_times will matter, and current_value = (initial_value + even_times) % 2. Otherwise, current_value = (initial_value + odd_times) % 2.

We can send (even_times, odd_times and level) as DFS parameters, so current_value can be calculated in O(1), and overall complexity is O(N).*/

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vint vector<int>
#define sint set<int>
#define mint map<int,int>
#define pint pair< int,int >
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define precision(x) cout<<fixed<<setprecision(x);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define present(container, element) (container.find(element)!=container.end())
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
void dfs(int node,vector<int>&lvl,vint * adj,vector<bool>& vis,int l){
	vis[node]=true;
	lvl[node]=l;
	for(auto child:adj[node]){
		if(!vis[child])
			dfs(child,lvl,adj,vis,l+1);
	}
}
int ans=0;
vector<int>Ans;
void cal(int node,vector<int>&lvl,vint * adj,vector<bool>& vis,bool odd,bool even,vint& prev,vint& curr){
	int c=prev[node];
	if(odd && lvl[node]&1)c=1-c;
	else if(even && lvl[node]%2==0)c=1-c;
	vis[node]=true;
	if(c!=curr[node]){
		ans++;
		Ans.pb(node);
		if(lvl[node]&1)odd=!odd;
		else even=!even;
	}	
	for(auto child:adj[node]){
		if(!vis[child])
			cal(child,lvl,adj,vis,odd,even,prev,curr);
	}
}
void solve(){
	int n;
	rd(n);
	vint level(n+1,0);
	vint adj[n+1];
	vector<bool>vis(n+1);
	FOR(i,n-1){
		int u,v;
		rd(u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	vint prev(n+1),curr(n+1);
	rep(i,1,n+1)rd(prev[i]);
	rep(i,1,n+1)rd(curr[i]);
	dfs(1,level,adj,vis,0);
	vis.clear();
	vis.resize(n+1);
	cal(1,level,adj,vis,false,false,prev,curr);
	pp(ans);
	for(auto v:Ans)pp(v);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}