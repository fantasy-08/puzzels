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
#define MOD 1000000007
using namespace std;
lli arr[10000000];
int main() {
    lli n,q,i,flag,lower=0,upper=0,ip1,ip2,ans=0,ans2;
    cin>>n>>q;
    FOR(ii,n)cin>>arr[ii];
    vector<lli> inc,dec;
    i=1;flag=0;
    // increasing array start
    for(lli j=0;j<n-1;j++){
        if(arr[j]<arr[j+1]){
            lower=j+1;
            while(j<n-1 && arr[j]<arr[j+1]){
                j++;
            }
            inc.pb(j+1);
        }
    }
    for(lli j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            lower=j+1;
            while(j<n-1 && arr[j]>arr[j+1]){
                j++;
            }
            dec.pb(j+1);
        }
    }
    lli inc1=inc.size(),dec1=dec.size();
    while(q--){
        ans=0;
        cin>>ip1>>ip2;
        auto itl=lower_bound(inc.begin(),inc.end(),ip1);
        auto itu=upper_bound(inc.begin(),inc.end(),ip2);
        ans=(itu-itl);
        auto itl1=lower_bound(dec.begin(),dec.end(),ip1);
        auto itu1=upper_bound(dec.begin(),dec.end(),ip2);
        ans2=(itu1-itl1);
        if(ans==ans2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
