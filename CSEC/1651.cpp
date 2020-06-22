
// Problem : Range Update Queries
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1651
// Memory Limit : 512 MB
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
const int maxN = 200001;
int ar[maxN];
int st[4*maxN] , lazy[4*maxN];
 
void build(int si , int ss , int se)
{
	if(ss == se)
	{
		st[si] = ar[ss];
		return;
	}
 
	int mid = (ss + se) / 2;
 
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
 
	st[si] = st[2*si] + st[2*si+1];
}
 
int query(int si , int ss , int se , int qs , int qe)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
 
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return 0;
 
	if(ss >= qs && se <= qe)
	return st[si];
 
	int mid = (ss + se) / 2;
	return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
}
 
void update(int si , int ss , int se , int qs , int qe , int val)
{
	if(lazy[si] != 0)
	{
		int dx = lazy[si];
		lazy[si] = 0;
		st[si] += dx * (se - ss + 1);
 
		if(ss != se)
		lazy[2*si] += dx , lazy[2*si+1] += dx;
	}
 
	if(ss > qe || se < qs) return;
 
	if(ss >= qs && se <= qe)
	{
		int dx = (se - ss + 1) * val;
		st[si] += dx;
 
		if(ss != se)
		lazy[2*si] += val , lazy[2*si+1] += val;
		return;
	}
 
	int mid = (ss + se) / 2;
	update(2*si , ss , mid , qs , qe , val);
	update(2*si+1 , mid+1 , se , qs , qe , val);
 
	st[si] = st[2*si] + st[2*si+1];
}

void solve(){
	int n,q;
	cin>>n>>q;
	rep(i,1,n+1)cin>>ar[i];
	build(1 , 1 , n);
	while(q--)
	{
		int l;
		cin>>l;
		if(l==2)
		{
			int r;
			cin>>r;
			cout<<query(1,1,n,r,r)<<endl;
		}
		else
		{
			int L,R,U;
			cin>>L>>R>>U;
			update(1,1,n,L,R,U);
		}
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
