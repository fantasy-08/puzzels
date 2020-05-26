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
int main() {
    string s;cin>>s;

    lli n=s.size(),ans=0;
    lli arr[n+1]={0};
    if(s[0]=='1')arr[1]=1;
    else arr[1]=0;
    for(lli i=2;i<=n;i++){
        if(s[i-1]=='1')arr[i]=arr[i-1]+1;
        else arr[i]=arr[i-1];
    }
   // FOR(i,n+1)cout<<arr[i]<<" ";
    for(lli i=1;i<n;i++){
        for(lli j=i;j<=n;j++){
            if(arr[j]-arr[i-1]!=0)
            if(((j-i+1)%(arr[j]-arr[i-1]))==0){ans+=1;}
            //cout<<endl;
        }
    }
    if(s[n-1]=='1')ans++;
    cout<<ans;
    return 0;
}
 