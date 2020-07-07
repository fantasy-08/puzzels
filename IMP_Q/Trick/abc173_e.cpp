#include<bits/stdc++.h>
#define speedio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
 
typedef long long       ll;
typedef long double     ld;
 
typedef vector<int>     vi;
typedef vector<bool>    vb;
typedef vector<ll>      vll;
typedef vector<vi>      vvi;
typedef vector<vll>     vvll;
typedef vector<string>  vs;
 
typedef pair<int, int>  pii;
typedef pair<ll, int>   pli;
typedef pair<ll, ll>    pll;
typedef vector< pii >   vpi;
 
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
 
#define pb           push_back
#define mod          1000000007
#define INF          1e17
#define mini         INT_MIN
#define maxo         INT_MAX
#define eb           emplace_back
#define ff           first
#define ss           second
#define re           return 
#define endl         "\n" 
 
#define all(c)       c.begin(),c.end()
#define be           begin()
#define en           end()
#define sz(x)        (ll)x.size()
#define mem(a,val)   memset(a,val,sizeof(a))
#define mk(x,y)      make_pair(x,y)
#define mid(s,e)     ((s)+((e)-(s))/2) 
 
#define fo(i,a,b)     for(int i = (int)(a); i <= (int)(b); i++)
#define rf(i,a,b)    for(int i = (int)(a); i >= (int)(b); i--)
#define read(a,n)    for(int i=0;i<n;i++)cin>>a[i];
#define show(a,n)    for(int i=0;i<n;i++)cout<<a[i]<<' ';cout<<endl;
#define p2(n)        (1LL << (n))
#define deb(x) cout <<#x << " = " << x << " | " << "LINE: "<<__LINE__<< endl;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
 
void add(ll &x, ll y){ x += y; if(x>=mod) x %= mod; if(x<0) x = x%mod + mod; }
 
//============== *** START OF CODE ***
 
 
bool comp(ll a,ll b){
    re abs(a)<abs(b);
}
 
ll mult(ll a,ll b){
    return a*b%mod;
}
 
void solve()
{
    ll n,k;rd(n,k);
    ll K = k;
    vll a(n);
    read(a,n);
    sort(all(a),comp);
    ll nPos = 0, nNeg = 0;
    vll pos,neg;
    for(ll x:a){
        if(x>=0){
            nPos++; pos.pb(x);
        }
        else{
            nNeg++; neg.pb(-x);
        }
    }   
    sort(all(pos),greater<int>());
    sort(all(neg),greater<int>());
    
    bool f = 1;
    int i=0,j=0;
    ll prod = 1;
    while(k){
        if(k==1){
            if(i<nPos){
                prod=mult(prod,pos[i]); k--; i++;
            }
            else {
                f = 0; break;
            }
        }
        else{
            if(i+1<nPos and j+1<nNeg){
                if(pos[i]*pos[i+1]>neg[j]*neg[j+1]){
                    prod = mult(prod,mult(pos[i],pos[i+1]));
                    i+=2;
                    k-=2;
                }
                else{
                    prod = mult(prod,mult(neg[j],neg[j+1]));
                    j+=2;
                    k-=2;
                }
            }
            else if(i+1<nPos and j+1>=nNeg){
                prod = mult(prod,mult(pos[i],pos[i+1]));
                i+=2;
                k-=2;
            }
            else if(i+1>=nPos and j+1<nNeg){
                prod = mult(prod,mult(neg[j],neg[j+1]));
                j+=2;
                k-=2;
            }
            else{
                f=0;
                break;
            }
        }
    }
 
 
    if(!f){
        k = K;
        prod = 1;
        fo(i,0,k-1){
            prod = mult(prod,a[i]);
        }
    }
    add(prod,0);
    pp(prod);
}
 
 
void prep(){}
 
//=============== *** END OF CODE ***
 
int main(){
    speedio; cout<<fixed<<setprecision(12);
 
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
 
    prep();
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
 
    cout<<"\n";
    return 0;
}
