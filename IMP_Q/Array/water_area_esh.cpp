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
int main() {
    lli n;cin>>n;
    lli arr[n];FOR(i,n)cin>>arr[i];
    lli ans=0;
    FOR(i,n-1){
        lli temp=0,flag=0;
        if(arr[i]==0) continue;
        rep(j,i+1,n){
            if(arr[j]>=arr[i]) {flag=j;break;}
            else{
                temp+=(arr[i]-arr[j]);
            }
        }
        if(flag) {ans+=temp;i=flag-1;continue;}
        else{
            lli temp2=0;
            temp=*max_element(arr+i+1,arr+n);
            flag=max_element(arr+i+1,arr+n)-arr;
            rep(j,i+1,flag+1){
                temp2+=temp-arr[j];
            }
            ans+=temp2;
            i=flag-1;
        }
    } 
    cout<<ans<<endl;
    return 0;
}
