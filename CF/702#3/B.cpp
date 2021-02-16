
// Problem : B. Balanced Remainders
// Contest : Codeforces - Codeforces Round #702 (Div. 3)
// URL : https://codeforces.com/contest/1490/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
#define input(a,n) int n;cin>>n;vint a(n);for(int&v:a)rd(v);
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
	int n;
	rd(n);
	int k=n/3;
	mint M;
	FOR(i,n)
	{
		int t;
		rd(t);
		M[t%3]++;
	}
	vector<pint>A(3);
	A[0]={M[0],0},A[1]={M[1],1},A[2]={M[2],2};
	if(A[0].ft==A[1].ft && A[1].ft==A[2].ft){
		pp(0);
	}
	else{
		sort(all(A));
		int ans=0;
		for(int i=2;i>=0;i--){
			int extra=A[i].ft-k;
			// Error(A[i].se,extra);
			if(extra<=0)break;
			while(extra)
			{
				for(int j=0;j<i;j++){
					if(A[j].ft<k){
						extra--;
						int from=A[i].se,to=A[j].se;
						for(int k=1;;k++){
							if((from+k)%3==to){
								ans+=k;
								A[j].ft++;
								break;
							}
						}
						break;
					}
				}
			}
		}
		pp(ans);
	}
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
