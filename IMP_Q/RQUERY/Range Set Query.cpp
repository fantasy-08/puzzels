
// Problem : E - Logs
// Contest : AtCoder - AtCoder Beginner Contest 174
// URL : https://atcoder.jp/contests/abc174/tasks/abc174_e
// Memory Limit : 1024 MB
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
#define BLK 1200
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
map<int,int>freq;
void add(int x){
	freq[x]++;
}
void remove(int x){
	freq[x]--;
	if(freq[x]==0){
		freq.erase(x);
	}
}
bool cmp(vector<int> A,vector<int> B){
	int X=A[0]/BLK,Y=B[0]/BLK;
	if(X!=Y)return X<Y;
	return X%2?A[1]<B[1]:A[1]>B[1];
}

void solve(){
	int n,q;
	rd(n,q);
	vector<int>arr(n+1);
	rep(i,1,n+1)rd(arr[i]);
	vector<vector<int>>Q;
	FOR(i,q){
		int l,r;
		cin>>l>>r;
		Q.pb({l,r,i});
	}
	sort(all(Q),cmp);
	int ML=1,MR=0;
	vector<int>ans(q);
	FOR(i,q){
		int L=Q[i][0];
		int R=Q[i][1];
		int index=Q[i][2];
		while(ML>L)	ML--,add(arr[ML]);
		while(MR<R) MR++,add(arr[MR]);
		while(MR>R) remove(arr[MR]),MR--;
		while(ML<L) remove(arr[ML]),ML++;
		ans[index]=freq.size();
	}
	for(int v:ans) pp(v);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
