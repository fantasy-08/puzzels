
// Problem : A. Sorting by Subsequences
// Contest : Codeforces - AIM Tech Round 4 (Div. 1)
// URL : https://codeforces.com/problemset/problem/843/A
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
	int n;
	cin>>n;
	vlli arr(n+1,0);
	arr[0]=INT_MIN;
	rep(i,1,n+1)cin>>arr[i];
	if(is_sorted(all(arr))){
		cout<<n<<endl;
		rep(i,1,n+1)cout<<1<<" "<<i<<endl;
		return ;
	}
	vlli Sort(arr);
	sort(all(Sort));
	// for(auto v:Sort)cerr<<v<<" ";
	// cerr<<endl;
	mlli ind;
	rep(i,1,n+1){
		ind[Sort[i]]=i;
	}
	// for(auto p:ind){
		// cerr<<p.ft<<" "<<p.se<<endl;
	// }
	vector<bool>used(n+1,false);
	vector<vlli>ans;
	rep(i,1,n+1){
		if(used[i]==false)
		{
			vlli temp;
			temp.pb(i);
			used[i]=true;
			int y=ind[arr[i]];
			// cerr<<i<<" ";
			while(y!=i){
				// cerr<<y<<" ";
				temp.pb(y);
				used[y]=true;
				y=ind[arr[y]];
			}
			// cerr<<endl;
			ans.pb(temp);
		}
	}
	cout<<ans.size()<<endl;
	for(auto v:ans){
		cout<<v.size()<<" ";
		for(auto val:v)cout<<val<<" ";
		cout<<endl;
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
