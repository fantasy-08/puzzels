
// Problem : C. Chocolate Bunny
// Contest : Codeforces - Codeforces Round #669 (Div. 2)
// URL : https://codeforces.com/contest/1407/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
// template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
// template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }

void solve(){
	int n;
	cin>>n;
	vint arr(n+1);
	set<int>s;
	rep(i,1,n+1)s.insert(i);
	int Q=n-1;
	set<int>val_f;
	while(Q--)
	{
		int u=*s.begin();
		s.erase(s.begin());
		int v=*s.begin();
		s.erase(s.begin());
		int A,B;
		cout<<"? "<<u<<" "<<v<<endl;
		cout.flush();
		cin>>A;
		cout.flush();
		cout<<"? "<<v<<" "<<u<<endl;
		cout.flush();
		if(A==-1)return;
		cin>>B;
		cout.flush();
		if(B==-1)return;
		//A arr(u)%arr(v);
		//B arr(v)%arr(u);
		val_f.insert(max(A,B));
		if(A>B){
			arr[u]=A;
			s.insert(v);
		}else{
			arr[v]=B;
			s.insert(u);
		}
	}	
	rep(i,1,n+1){
		if(val_f.count(i)==0){
			arr[*s.begin()]=i;
			break;
		}
	}	
	cout<<"! ";
	rep(i,1,n+1){
		cout<<arr[i]<<" ";
	}
	cout.flush();
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
