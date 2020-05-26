#include <bits/stdc++.h>
#define FOR(i,n) for(long long int i=0;i<n;i++)
#define FORR(i,n) for(long long int i=n;i>=0;i--)
#define pb push_back
#define set(arr,x) memset(arr,x,sizeof(arr))
#define vlli vector<long long int>
#define slli set<long long int>
#define mlli map<long long int,long long int>
#define lli long long int 
#define test lli tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define count1(x) __builtin_popcount(x)
#define MOD 1000000007
using namespace std;
int main() {
    lli n,m,k,temp;
    cin>>n>>m>>k;
    lli arr[m],f;
    FOR(i,m)cin>>arr[m];
    cin>>f;
    if(k>=n)cout<<n<<endl;
    else{
        lli count=0;
        FOR(i,m){
            temp=f^arr[i];
            if(count1(temp)<=k)count++;
        }
        cout<<count<<endl;
    }
    
}
