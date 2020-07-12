
// Problem : A. Thor
// Contest : Codeforces - Codeforces Round #366 (Div. 1)
// URL : https://codeforces.com/problemset/problem/704/A
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define plii pair< int,int >
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

void solve(){
	int n,q;
	rd(n,q);
	map<int,vector<list<int>::iterator>>m;
	list<int>arr;
	int noti=0;
	while(q--)
	{
		int t,x;
		rd(t,x);
		if(t==1){
			arr.push_back(x);
			noti++;
			m[x].pb(prev(arr.end()));
		}
		else if(t==2)
		{
			noti-=m[x].size();
			for(auto v:m[x]){
				arr.erase(v);
			}
			m[x].clear();
		}
		else{
			noti-=x;
			noti=max(noti,0LL);
			while(x-- && arr.size()){
				auto it=arr.begin();
				m[*it].erase(m[*it].begin());
				arr.erase(it);
			}
			
		}
		pp(noti);
	}
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
