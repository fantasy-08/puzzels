
// Problem : Maximize LCM
// Contest : CodeChef - March Lunchtime 2020 Division 1
// URL : https://www.codechef.com/LTIME82A/problems/MXMLCM
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(long long int i=0;i<n;i++)
#define FORR(i,n) for(long long int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<long long int>
#define slli set<long long int>
#define mlli map<long long int,long long int>
#define lli long long int 
#define test lli tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
#define ll long long
using namespace std;
const int limit = 10000;
vector<bool> prime(limit + 1, true);

vector<vector<pair<int, int> > > factor(limit + 1);
void SieveOfEratosthenes() 
{ 
	for (int i = 1; i <= limit; ++i) {
		int x = i;
		for (int j = 2; j * j <= x; ++j) {
			if (x % j == 0) {
				int cnt = 0;
				while (x % j == 0) {
					x /= j;
					++cnt;
				}
				factor[i].push_back(make_pair(j, cnt));
			}
		}
		if (x > 1) {
			factor[i].push_back(make_pair(x, 1));
		}
	}
    prime[0] = false;
	prime[1] = false;
	for (int i = 2; i <= limit; ++i) {
		if (!prime[i]) continue;
		for (int j = i * 2; j <= limit; j += i) {
			prime[j] = false;
		}
	}
  
} 
void solve(){
int N, M;
		cin >> N >> M;
		vector<int> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
	vector<int> mx(M + 1);
		for (int i = 0; i < N; ++i) {
			for (pair<int, int> j : factor[A[i]]) {
				mx[j.first] = max(mx[j.first], j.second);
			}
		}
		int opt = 0, ans = -1;
		for (int i = 1; i <= M; ++i) {
			int mul = 1;
			for (pair<int, int> j : factor[i]) {
				if (j.second > mx[j.first]) {
					for (int k = mx[j.first]; k < j.second; ++k) {
						mul *= j.first;
					}
				}
			}
			if (opt < mul) {
				opt = mul;
				ans = i;
			}
		}
		cout << ans << '\n'; 
	return;	
}


int32_t main() {
	SieveOfEratosthenes();
    fint{
    	solve();
    }
    return 0;
}
