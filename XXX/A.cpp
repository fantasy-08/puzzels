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
        lli arr[n],maxx=-1,flag=0,k=-1,z=0,sum=0;
        FOR(i,n){
            cin>>arr[i];
            sum+=arr[i];
            if(arr[i]==-1){z++;sum++;}
            else flag++;
        }
        if(flag==0){
            cout<<0<<" "<<0<<endl; 
            continue;
        }
        lli mxx=0;
        FOR(i,n-1){
            if(arr[i]!=-1 && arr[i+1]!=-1)
            if(abs(arr[i]-arr[i+1])>maxx) mxx=abs(arr[i]-arr[i+1]);
        }
        k=(sum)/flag;
        lli max2=-1;
        lli k2=ceil((sum)/(1.0*flag));
        vlli dope;
        FOR(i,n){
            if(arr[i]==-1) dope.pb(k2);
            else dope.pb(arr[i]);
        }
        FOR(i,n-1){
            if(abs(dope[i]-dope[i+1])>max2) max2=abs(dope[i]-dope[i+1]);
        }
        FOR(i,n)
            if(arr[i]==-1) arr[i]=k;
        FOR(i,n-1){
            if(abs(arr[i]-arr[i+1])>maxx) maxx=abs(arr[i]-arr[i+1]);
        }
        if(mxx==maxx) cout<<maxx<<" "<<k<<endl;
        else
        cout<<max2<<" "<<k2<<endl;
        }
     
    return 0;
}
