
// Problem : B. Misha and Changing Handles
// Contest : Codeforces - Codeforces Round #285 (Div. 2)
// URL : https://codeforces.com/problemset/problem/501/B
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
int par[5000];
int find(int a){
	while(a!=par[a]){
		par[a]=par[par[a]];
		a=par[a];
	}
	return a;
}

void unite(int a, int b){
	int P1=find(a);
	int P2=find(b);
	par[P1]=par[P2];
}


void solve(){
	for(int i=1;i<5000;i++)par[i]=i;
	int n;
	cin>>n;
	map<string,int>m;
	map<int,string>mi;
	set<string>s,org;
	int x=1;
	FOR(i,n){
		string a,b;
		cin>>a>>b;
		int P1,P2;
		if(m.find(a)!=m.end()){
			P1=m[a];
		}
		else{
			m[a]=x;
			mi[x]=a;
			P1=x;
			x++;
		}
		if(m.find(b)!=m.end()){
			P2=m[b];
		}
		else{
			m[b]=x;
			mi[x]=b;
			P2=x;
			x++;
		}
		s.insert(b);
		org.insert(a);
		unite(P1,P2);
	}
	vector<pair<string,string>>ans;
	for(auto str:org){
		if(s.find(str)!=s.end())continue;
		int parent=find(m[str]);
		ans.pb({str,mi[parent]});
	}
	cout<<ans.size()<<endl;
	for(auto Pair:ans)cout<<Pair.ft<<" "<<Pair.se<<endl;
	
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
