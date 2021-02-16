
// Problem : G. Old Floppy Drive
// Contest : Codeforces - Codeforces Round #702 (Div. 3)
// URL : https://codeforces.com/contest/1490/problem/G
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
	int n,q;
	rd(n,q);
	vint arr(n);
	
	for(int &v:arr)rd(v);
	
	vint pre(n);
	pre[0]=arr[0];
	for(int i=1;i<n;i++)pre[i]=arr[i]+pre[i-1];
	
	int M=*max_element(all(pre));
	vector<int>pos,ind;
	for(int i=0;i<n;i++){
		if(pos.size()==0){
			if(pre[i]>0){
				pos.pb(pre[i]);
				ind.pb(i);
			}
		}
		else{
			int prev=pos[pos.size()-1];
			if(pre[i]>prev){
				pos.pb(pre[i]);
				ind.pb(i);
			}
		}
	}
	
	while(q--)
	{
		int sum;
		rd(sum);
		if(M>=sum){
			int l=lower_bound(all(pos),sum)-pos.begin();
			cout<<(ind[l])<<" ";
		}
		else if(pre[n-1]<=0){
			cout<<-1<<" ";
		}
		else{
			sum-=M;
			int count=ceil(sum/(pre[n-1]*1.0));
			int rem=sum+M-(count*pre[n-1]);
			int l=lower_bound(all(pos),rem)-pos.begin();
			cout<<(ind[l]+count*n)<<" ";
		}
	}
	cout<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
