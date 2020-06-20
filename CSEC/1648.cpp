
// Problem : Range Sum Queries II
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1648
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int n;
vi t;

void add(int k, ll x) {
  while (k <= n) {
    t[k] += x;
    k += k & -k;
  }
}

ll sum(int k) {
  ll s = 0;
  while (k >= 1) {
    s += t[k];
    k -= k & -k;
  }
  return s;
}

ll sum(int a, int b) {
  return sum(b) - sum(a - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q, r, a, b;
  cin >> n >> q;
  vi x(n);
  t = vi(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    add(i + 1, x[i]);
  }
  for (int i = 0; i < q; i++) {
    cin >> r >> a >> b;
    if (r == 1) {
      add(a, b - x[a - 1]);
      x[a - 1] = b;
    }
    else cout << sum(a, b) << "\n";
  }
}
/*//#pragma GCC optimize "trapv"//  WA to RE int!!
/*
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
int arr[200005];
int tree[500005];

void build(int ind,int s,int e)
{
	if(s==e)
	{
		tree[ind]=arr[s];
		return;
	}
	int mid=s+(e-s)/2;
	build(2*ind,s,mid);
	build(2*ind+1,mid+1,e);
	tree[ind]=(tree[2*ind]+tree[2*ind+1]);
}

int query(int ind,int ss,int se,int qs,int qe)
{
	if(ss>=qs && se<=qe)
	{
		return tree[ind];
	}
	if(se<qs || ss>qe)return 0;
	int mid=ss+(se-ss)/2;
	int l=query(2*ind,ss,mid,qs,qe);
	int r=query(2*ind+1,mid+1,se,qs,qe);
	return (l+r);
}

void update(int ind,int ss,int se,int pos,int val)
{
	if(ss==se)
	{
		arr[pos] =val;
		tree[ind]=val;
		return ;
	}
	int mid=ss+(se-ss)/2;
	if(ss<=pos && pos<=mid)
		update(2*ind,ss,mid,pos,val);
	else
		update(2*ind+1,mid+1,se,pos,val);
	tree[ind]=tree[2*ind]+tree[2*ind+1];
}


void solve(){
	int n,q;
	cin>>n>>q;
	rep(i,1,n+1)
	{
		cin>>arr[i];
	}
	build(1,1,n);
	while(q--)
	{
		int o,l,r;
		cin>>o>>l>>r;
		if(o==2)
			cout<<query(1,1,n,l,r)<<endl;
		else 
			update(1,1,n,l,r);
	}
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}*/