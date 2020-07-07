
// Problem : D. Solve The Maze
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/D
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
	int n,m;
	cin>>n>>m;
	char org[n][m];
	int good=0,bad=0;
	queue<pair<int,int>>G,B,BB;
	bool vis[n][m],vis1[n][m];
	memset(vis,false,sizeof(vis));
	memset(vis1,false,sizeof(vis1));
	FOR(i,n){
		FOR(j,m){
			char t;
			cin>>t;
			org[i][j]=t;	
			if(t=='G')good++;
			else if(t=='B')bad++;
			if(t=='G')G.push({i,j}),vis[i][j]=true;
			if(t=='B')B.push({i,j}),BB.push({i,j}),vis1[i][j]=true;
		}
	}
	if(good==0){
		cout<<"Yes\n";
		return;
	}
	if(org[n-1][m-1]=='#'){
		cout<<"No\n";
		return;
	}
	
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};
	
	while(G.size()){
		int u=G.front().ft;
		int v=G.front().se;
		G.pop();
		FOR(i,4){
			int X=u+dx[i];
			int Y=v+dy[i];
			if(X>=0 && X<n && Y>=0 && Y<m && org[X][Y]!='#' && vis[X][Y]==false){
				vis[X][Y]=true;
				G.push({X,Y});
			}
		}
	}
	if(vis[n-1][m-1]==false){
		cout<<"No\n";
		return;
	}
	
	// while(B.size()){
		// int u=B.front().ft;
		// int v=B.front().se;
		// B.pop();
		// FOR(i,4){
			// int X=u+dx[i];
			// int Y=v+dy[i];
			// if(X>=0 && X<n && Y>=0 && Y<m && org[X][Y]!='#' && vis1[X][Y]==false){
				// vis1[X][Y]=true;
				// B.push({X,Y});
			// }
		// }
	// }
	while(BB.size()){
		int u=BB.front().ft;
		int v=BB.front().se;
		BB.pop();
		if(vis[u][v]==1){
			vis[u][v]=0;
		}
		FOR(i,4){
			int X=u+dx[i];
			int Y=v+dy[i];
			if(X>=0 && X<n && Y>=0 && Y<m && vis[X][Y]==1){
				vis[X][Y]=false;
			}
		}
	}
	queue<pair<int,int>>q;
	if(vis[n-1][m-1]==0){
		cout<<"No\n";
		return ;
	}
	bool vis11[n][m];
	memset(vis11,false,sizeof(vis1));
	q.push({n-1,m-1});
	vis1[n-1][m-1]=1;
	int gc=0;
	while(q.size()){
		int u=q.front().ft;
		int v=q.front().se;
		q.pop();
		// cout<<u<<" "<<v<<endl;
		if(org[u][v]=='G')gc++;
		for(int i=0;i<4;i++){
			int X=u+dx[i];
			int Y=v+dy[i];
			if(X>=0 && X<n && Y>=0 && Y<m && vis[X][Y]==true && vis11[X][Y]==false){
				vis11[X][Y]=true;
				q.push({X,Y});
			}
		}
	}
	
	memset(vis11,false,sizeof(vis1));
	q.push({n-1,m-1});
	vis1[n-1][m-1]=1;
	int bc=0;

	if(gc==good && bc==0){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
	return;
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
