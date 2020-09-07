
// Problem : C. Yet Another Array Restoration
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// God & me
// Fly ...
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

void solve(){
	int n,a,b;
	rd(n,a,b);
	int dif=abs(a-b);
	if(b<a)swap(a,b);
	vector<int>pos;
	for(int i=1;i*i<=dif;i++){
		if(dif%i==0){
			pos.pb(i);
			if((dif/i)!=i) pos.pb(dif/i);
		}	
	}
	int ans=a+(n-1)*(b-a),D=b-a;
	for(auto v:pos)
	{
		int term=a+(n-1)*v;
		if(term==b){ans=b,D=v;break;}
		else if(term<b)continue;
		else{
			int start=a%v;
			if(start==0)start+=v;		
			int nterm=start+(n-1)*v;
			if(nterm<b){ans=b,D=v;break;}
			else{
				if(nterm<ans)
				{
					ans=nterm;
					D=v;								
				}
			}
		}
	}
	int X=ans;
	FOR(i,n){
		cout<<X<<" ";
		X-=D;
	}
	pp("");
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
