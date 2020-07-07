
// Problem : Hotel Queries
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1143
// Memory Limit : 512 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
#include <bits/stdc++.h>
using namespace std;
 
struct node {
	int range_max;
	
	node() {
		range_max = 0;
	}
};
 
class SegmentTree {
public:
	SegmentTree(int n) : n_(n) {
		tree_.resize(4 * n_);
	}
	~SegmentTree() = default;
 
	int GetPos(int reqd, int l, int r, int pos = 1) {
		if (tree_[pos].range_max < reqd) return 0;
		if (l == r) return l;

		int mid = (l + r) / 2;
		if (tree_[2 * pos].range_max >= reqd)
			return GetPos(reqd, l, mid, 2 * pos);
		else
			return GetPos(reqd, mid + 1, r, 2 * pos + 1);
	}
 
	void point_update(int idx, int val, int l, int r, int pos = 1) {
		if (l == r) {
			tree_[pos].range_max = val;
			return;
		}
		int mid = (l + r) / 2;
		if (mid >= idx)
			point_update(idx, val, l, mid, 2 * pos);
		else
			point_update(idx, val, mid + 1, r, 2 * pos + 1);
		tree_[pos] = merge(tree_[2 * pos], tree_[2 * pos + 1]);
	}
 
private:
	node merge(const node& l, const node& r) {
		node ret;
		ret.range_max = max(l.range_max, r.range_max);
		return ret;
	}
 
	vector<node> tree_;
	int n_;
};
 
int main() {
	int n, q;
	cin >> n >> q;
	SegmentTree st(n);
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		st.point_update(i, arr[i], 1, n);
	}
	while(q--) {
		int x;
		cin >> x;
		int v = st.GetPos(x, 1, n);
		cout << v << " ";
		if (v) {
			arr[v] -= x;
			st.point_update(v, arr[v], 1, n);
		}
	}
	return 0;
}/*
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
	tree[ind]=max(tree[2*ind],tree[2*ind+1]);
}

int query(int ind,int ss,int se,int qs,int qe)
{
	if(ss>=qs && se<=qe)
	{
		return tree[ind];
	}
	if(se<qs || ss>qe)return -1;
	int mid=ss+(se-ss)/2;
	int l=query(2*ind,ss,mid,qs,qe);
	int r=query(2*ind+1,mid+1,se,qs,qe);
	return max(l,r);
}

void update(int ind,int ss,int se,int pos,int val)
{
	if(ss==se)
	{
		arr[pos]=val;
		tree[ind]=val;
		return ;
	}
	int mid=ss+(se-ss)/2;
	if(ss<=pos && pos<=mid)
		update(2*ind,ss,mid,pos,val);
	else
		update(2*ind+1,mid+1,se,pos,val);
	tree[ind]=max(tree[2*ind],tree[2*ind+1]);
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,1,n+1)cin>>arr[i];
	build(1,1,n);
	// error(query(1,1,n,4,4));
	while(m--)
	{
		int q;
		cin>>q;
		int l=1,h=n;
		if(query(1,1,n,1,n)<q)
		{
			cout<<0<<" ";
			continue;
		}
		while(l<=h)
		{
			int mid=l+(h-l)/2;
			int A=query(1,1,n,l,mid);
			if(l==h)
			{
				cout<<l<<" ";
				update(1,1,n,l,arr[l]-q);
				break;
			}
			if(A>=q)
			{
				h=mid-1;
			}
			else
			{
				l=mid+1;
			}
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
*/