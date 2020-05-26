#include<bits/stdc++.h>
#define int long long int
using namespace std;


int const mod = 1e9+7;
int power(int a,int b,int m){
    int res = 1;
    while(b){
        if(b&1){
            res = res*a;
            res %= m;
        }
        a=a*a;
        a%=m;
        b=b/2;
    }
    return res;
}

int inverse(int x){
    return power(x,mod-2,mod);
}

int const N = 1e6+55;
int const inf = 2e16;
int fact[N], ifact[N];

void precompute(){
    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = fact[i-1]*i;
        fact[i] %= mod;
    }
    ifact[N-1] = inverse(fact[N-1]);
    for(int i=N-2;i>=0;i--){
        ifact[i] = (i+1)*ifact[i+1];
        ifact[i] %= mod;
    }
}

int ncr(int n,int r){
    if(r < 0) return 0;
    if(r > n) return 0;
    if(n == r) return 1;
    int res = fact[n];
    res = res*ifact[n-r];
    res %= mod;
    res = res*ifact[r];
    res %= mod;
    return res;
}

void solve(){
    int n,i,j,l,k;
    int a,b,m;
    cin>>a>>b>>n>>m;

    int ans = 0;
    int f1 = ncr(n-1 , m-1);
    int f2 = ncr(n-1 , m-2);

    ans = f1*a;
    ans %= mod;
    ans = ans + b*f2;
    ans %= mod;
    cout<<ans<<endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t;
    t = 1;
    precompute();
    cin>>t;
    for(int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}
