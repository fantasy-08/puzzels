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
vlli divi;
void printDivisors(lli n) 
{ 
    divi.clear(); 
    for (lli i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                {divi.pb(i);} 
  
            else // Otherwise print both 
                {divi.pb(i);divi.pb(n/i);} 
        } 
    } 
    //sort(divi.begin(),divi.end());
} 
  
int main() {
    test{
        lli n,m,temp,z=0,ans=0,ndivi,temp1,tempn,tempn1,tt;
        //long double temp1;
        cin>>n>>m;
        vlli px,nx,py,ny,x,y;
        map<lli,int>hashx,hashy,hh,hh1;
        FOR(i,n){
            cin>>temp;
            x.pb(temp);
            hashx[temp]=9;
        }
        FOR(i,m){
            cin>>temp;
            y.pb(temp);
            hashy[temp]=9;
        }
        if(z){
             ans+=x.size()*y.size();
        }
        // x points
        FOR(i,y.size()){
            tt=abs(y[i]);
            tt*=tt;
            printDivisors(tt);
            ndivi=divi.size();
            FOR(j,(ndivi)){
                if(hh[divi[j]]==0 && hh[tt/divi[j]]==0){
                temp=divi[j];
                temp1=tt/temp;
                if(temp!=temp1){
                tempn=-1*temp;
                tempn1=-1*temp1;
                if(hashx[temp]==9 && hashx[tempn1]==9) ans++;
                if(hashx[tempn]==9 && hashx[temp1]==9) ans++;}
                 else{
                    if(hashx[temp]==9 && hashx[-1*temp]==9) ans++;
                }
                hh[divi[j]]==9;hh[tt/divi[j]]==9;
                }
            }
        }
        //cout<<"ans"<<ans<<endl;
        FOR(i,x.size()){
            tt=abs(x[i]);
            tt*=tt;
            printDivisors(tt);
            ndivi=divi.size();
            FOR(j,(ndivi/2 )){
                if(hh1[divi[j]]==0 && hh1[tt/divi[j]]==0){
                temp=divi[j];
                temp1=tt/divi[j];
                if(temp!=temp1){
                tempn=-1*temp;
                tempn1=-1*temp1;
                if(hashy[temp]==9 && hashy[tempn1]==9) ans++;
                if(hashy[tempn]==9 && hashy[temp1]==9) ans++;}
                else{
                    if(hashy[temp]==9 && hashy[-1*temp]==9) ans++;
                }
                hh1[divi[j]]==9;hh1[tt/divi[j]]==9;
                }
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
