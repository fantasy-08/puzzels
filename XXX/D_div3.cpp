
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
#define present(container, element) (container.find(element)!=container.end())
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
using namespace std;
const int Nmax = 100005;
const int INF = 1000000000;
const int MOD = 998244353;
 
 
char s[Nmax];
int b[Nmax];
int n, m;
 

int cost(vector<char>& ans, int pos, char c) {
    int total = 0;
    for(int i = 1; i <= m; i++) {
        if(i != pos && ans[i] != '.' && ans[i] > c) {
            total += abs(i - pos);
        }
    }
    return total;
}
 
int32_t main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> (s + 1) >> m;
        n = strlen(s + 1);
        vector<int> fr(26, 0);
        for(int i = 1; i <= n; i++) {
            fr[s[i] - 'a']++;
        }
        for(int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        char c = 'z';
        vector<char> ans(m + 1, '.');
        while(true) {
            vector<int> zeros;
            for(int i = 1; i <= m; i++) {
                if(b[i] == 0) {
                    zeros.push_back(i);
                    b[i] = -1;
                }
            }
            if(zeros.empty()) break;
            while(c >= 'a' && fr[c - 'a'] < zeros.size()) {
                c--;
            }
            for(int pos : zeros) {
                ans[pos] = c;
            }
            for(int i = 1; i <= m; i++) {
                if(ans[i] == '.' || ans[i] < c) {
                    for(int pos : zeros) {
                        b[i] -= abs(pos - i);
                    }
                }
            }
            c--;
        }
        for(int i = 1; i <= m; i++)
            cout << ans[i];
        cout << "\n";
    }
    return 0;
}