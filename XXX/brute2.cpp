//#pragma GCC optimize "trapv"//  WA to RE int!!
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
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
using namespace std;
lli arr[2000],n,h,l,r;
lli dp[2000][2000];
lli go(lli i,lli time){
    if(i==n) {
        return 0;
    }
    if(dp[i][time]!=-1) return dp[i][time];
    lli t1=(time+arr[i])%h,t2=(time+arr[i]-1)%h,z=0,z1=0;
    if(t1>=l && t1<=r) z=1;
    if(t2>=l && t2<=r) z1=1;
    dp[i][time]=max((go(i+1,t1)+z),(go(i+1,t2)+z1));
    return dp[i][time];
}
int main() {
    fast
    memset(dp,-1,sizeof(dp));
    cin>>n>>h>>l>>r;
    FOR(i,n) cin>>arr[i];
    cout<<go(0,0);
    return 0;
}