#include <bits/stdc++.h>
using namespace std;
// using namespace __gnu_pbds;
// template <class c, class cmp = less<c> > using ordered_set = tree<c, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
 
 
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL); 
 
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define in insert
#define ld long double
 
 
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =998244353;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll maxn = 100000+10;
#define endl '\n'
#define int ll
ll power(ll x, ll n) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
	if (n & 1) res = (res * x) % mod;
	x = (x * x) % mod;
	}
	return res;
}
map<ll, ll> par;

ll getPar(ll v){
	if (!par.count(v))
		par[v] = v;
	return par[v]==v? v: par[v]=getPar(par[v]);
}
int computeXOR(int n) 
{ 
    switch(n & 3) 
    { 
    case 0: return n;     // if n is multiple of 4 
    case 1: return 1;     // If n % 4 gives remainder 1   
    case 2: return n + 1; // If n % 4 gives remainder 2     
    case 3: return 0;     // If n % 4 gives remainder 3   
    } 
	return 0;
} 

int32_t main()
{   
 
   #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif 
    IOS 
	int n,q;
	cin>>n>>q;
	set<int> s;
	s.in(n+1);
	while(q--)
	{
		int t,i;
		cin>>t>>i;
		if(t==1)
		{	
			par[i] = i+1;
			s.in(i);
		}
		else
		{
			int st = getPar(i);
			int en = *s.upper_bound(st);
			int ans =  computeXOR(en-1)^(computeXOR(st-1));
			cout<<ans<<endl;
		}
		
	}
	
 
}
// All submissions for this problem are available.Its Christmas time and Santa wants to distribute presents in your city. The city is a straight line with houses numbered 1 to n, where n is the number of houses. Initially all the houses have 0 presents. Santa can perform two types of tasks:

// 1 i:Santa drops a present in the ith house.
// 2 i: Santa calculates magic number for the ith house.
// The magic number for the ith house is the xor of the house numbers of first continuous sequence of houses with house number ≥i and having 0 presents.

// Print output of each task of type 2 in a new line. It is guaranteed that the magic number always exists, i.e the sequence of houses always exists.
