#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#define f0r(a, b) for (long long a = 0; a < (b); ++a)
#define f1r(a, b, c) for (long long a = (b); a < (c); ++a)
#define f0rd(a, b) for (long long a = (b); a >= 0; --a)
#define f1rd(a, b, c) for (long long a = (b); a >= (c); --a)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define fix(prec) {cout << setprecision(prec) << fixed;}
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(), v.end()
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < (n); ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = (lb); ele <= (rb); ele++) { if (ele > (lb)) cout << " "; cout << a[ele]; } cout << '\n';}
#define vsz(x) ((long long) x.size())
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
struct dijkstra {
  int n;
  const ll inf = 4e18;
  vector<ll> dists; /* for a single run */
  vector<int> par;
  vector<bool> vis;
  vector<vector<pair<ll, int> > > edges; /* weight, to */
  
  void init(int s) {
    n = s;
    dists = vector<ll>(n);
	  vis = vector<bool>(n);
    par = vector<int>(n);
    edges = vector<vector<pair<ll, int> > >(n);
  }
 
  void edge(int a, int b, ll wt) {
    edges[a].push_back(make_pair(wt, b));
  }
 
  using ptype = pair<ll, int>;
  void run(int src) {
    fill(dists.begin(), dists.end(), inf);
	  fill(vis.begin(), vis.end(), false);
    fill(par.begin(), par.end(), -1);
 
    priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
    dists[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
      ptype foc = pq.top();
      pq.pop();
	  
	    if (vis[foc.s]) continue;
	    vis[foc.s] = 1;
	  
      dists[foc.s] = min(dists[foc.s], foc.f);
      for (ptype x: edges[foc.s]) {
        ll d = dists[foc.s] + x.f;
        if (d < dists[x.s]) {
          dists[x.s] = d;
          par[x.s] = foc.s;
          pq.push(make_pair(d, x.s));
        }
      }
    }
  }
};
 
ll n, m, k, q, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 
dijkstra d;
string ss[51];
 
ll pack(ll strnum, ll side, ll unbalanced) {
	return strnum * 2 * 21 + side * 21 + unbalanced;
}
 
void solve(int tc) {
	cin >> n;
	
	ll mx = (n + 2) * 2 * 21;
	d.init(mx);
	
	f0r(i, n) {
		cin >> ss[i] >> c[i];
		d.edge(0, pack(i + 1, 0, ss[i].length()), c[i]);
		d.edge(0, pack(i + 1, 1, ss[i].length()), c[i]);
	}
	
	const ll inf = 1e18;
	ans = inf;
	f0r(i, n) {
		bool pal = 1;
		f0r(j, ss[i].length() / 2) {
			if (ss[i][j] != ss[i][ss[i].length() - j - 1]) pal = 0;
		}
		if (pal) {
			ans = min(ans, c[i]);
		}
	}
	
	ll finstate = pack(1, 0, 0);
	
	f0r(i, n) {
		f1r(unbal, 2, 21) {
			// left
			f0r(j, n) {
				ll req = min(unbal, (ll)ss[j].length());
				ll newstr = i + 1, side = 0, nbal;
				if (ss[j].length() > unbal) {
					newstr = j + 1;
					side = 1;
					nbal = ss[j].length() - unbal;
				} else {
					nbal = unbal - ss[j].length();
				}
				
				bool pos = 1;
				ll start = ss[i].length() - unbal;
				f0r(k, req) {
					if (ss[i][start + k] != ss[j][ss[j].length() - 1 - k]) {
						pos = 0;
						break;
					}
				}
				
				ll nid = pack(newstr, side, nbal);
				if (pos) {
					ll curid = pack(i + 1, 0, unbal);
					d.edge(curid, nid, c[j]);
				}
				
				bool rpal = 1;
				if (ss[j].length() > unbal) {
					f0r(i, nbal / 2) {
						if (ss[j][i] != ss[j][nbal - i - 1]) rpal = 0;
					}
				} else {
					f0r(k, nbal / 2) {
						if (ss[i][ss[i].length() - nbal + k] != ss[i][ss[i].length() - 1 - k]) rpal = 0;
					}
				}
				if (rpal) {
					d.edge(nid, finstate, 0);
				}
			}
			
			// right
			f0r(j, n) {
				ll req = min(unbal, (ll)ss[j].length());
				ll newstr = i + 1, side = 1, nbal;
				if (ss[j].length() > unbal) {
					newstr = j + 1;
					side = 0;
					nbal = ss[j].length() - unbal;
				} else {
					nbal = unbal - ss[j].length();
				}
				
				bool pos = 1;
				f0r(k, req) {
					if (ss[j][k] != ss[i][unbal - 1 - k]) {
						pos = 0;
						break;
					}
				}
				
				ll nid = pack(newstr, side, nbal);
				if (pos) {
					ll curid = pack(i + 1, 1, unbal);
					d.edge(curid, nid, c[j]);
				}
				
				bool rpal = 1;
				if (ss[j].length() > unbal) {
					f0r(i, nbal / 2) {
						if (ss[j][unbal + i] != ss[j][ss[j].length() - i - 1]) rpal = 0;
					}
				} else {
					f0r(k, nbal / 2) {
						if (ss[i][k] != ss[i][nbal - 1 - k]) rpal = 0;
					}
				}
				if (rpal) {
					d.edge(nid, finstate, 0);
				}
			}
		}
	}
	
	d.run(0);
	
	f0r(i, n) {
		f0r(unbal, 2) {
			f0r(side, 2) {
				ll id = pack(i + 1, side, unbal);
				ans = min(ans, d.dists[id]);
			}
		}
	}
	
	if (ans == inf) ans = -1;
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	// usaco("cowland");
 
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
} 