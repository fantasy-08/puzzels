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
    test{
        lli n;
        cin>>n;
        lli arr[n],zero=0,maxx=-1,flag=0,k=-1;
        FOR(i,n){
            cin>>arr[i];
            if(arr[i]==-1) zero++;
        }
        if(zero==n && 0) cout<<0<<" "<<3<<endl;
        else{
            FOR(i,n-1){
                if(arr[i]!=-1 && arr[i+1]!=-1)
                if(abs(arr[i]-arr[i+1])>maxx) maxx=abs(arr[i]-arr[i+1]);
                else{
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<0<<" "<<3<<endl;
            }
            else{
                vlli sum;
                FOR(i,n-1){
                    if(arr[i]==-1){
                        if(i!=n)sum.pb(arr[i+1]);
                        i++;
                    }
                    else{
                        if(i!=n)
                            if(arr[i+1]==-1)
                                sum.pb(arr[i]);
                    }
                }
                flag=0;
                FOR(i,sum.size()) flag+=sum[i];
                k=ceil(flag/(1.0*sum.size()));
                flag=0;
                FOR(i,n){
                    if(arr[i]==-1) arr[i]=k;
                }
                maxx=-1;
                FOR(i,n-1){
                    if(abs(arr[i]-arr[i+1])>maxx) maxx=abs(arr[i]-arr[i+1]);
                }
                cout<<maxx<<" "<<k<<endl;
            }

            }
        }
     
    return 0;
}
