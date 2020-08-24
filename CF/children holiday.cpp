
// Problem : D. Children Holiday
// Contest : Codeforces - ITMO Academy: pilot course - Binary Search - Step 2
// URL : https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
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
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
int n,m;
vector<vector<int>>v;
bool chk(vint v,int k,int C){
	int t=v[0],z=v[1],y=v[2];
	int X=k/z;
	if(k%z==0 && X!=0)X--;
	int Work=k*t+X*y;
	return Work<=C;
}
pair<bool,vint>go(int c){
	vint count(m,0);
	int tot=0;
	FOR(i,m){
		int l=0,h=INT_MAX;
		int ans=0;
		while(l<=h){
			int mid=l+(h-l)/2;
			bool pos=chk(v[i],mid,c);
			if(pos){
				ans=mid;
				l=mid+1;
			}else h=mid-1;
		}
		count[i]=ans;
		tot+=ans;
	}
	bool res=(tot>=n);
	return {res,count};
}

void solve(){
	rd(n,m);
	FOR(i,m){
		int t,z,y;
		rd(t,z,y);
		v.pb({t,z,y});
	}	
	int l=0,h=INT_MAX;
	int  ans=0;
	vint Ans;
	while(l<=h){
		int mid=l+(h-l)/2;
		auto X=go(mid);
		if(X.ft){
			ans=mid;
			Ans=X.se;
			h=mid-1;
		}
		else l=mid+1;
	}
	pp(ans);
	int extra=0;
	for(auto v:Ans)extra+=v;
	extra-=n;
	FOR(i,Ans.size()){
		if(Ans[i]>extra){
			Ans[i]-=extra;
			extra=0;
		}
		else{
			extra-=Ans[i];
			Ans[i]=0;
		}
	}
	for(auto v:Ans)cout<<v<<" ";
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
