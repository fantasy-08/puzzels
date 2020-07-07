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
string check(string a,string b){
    string c="";
    int z;
    for(lli i=0;i<a.size();i++){
        if(a[i]==b[i]) c+=a[i];
        else{
            z=a[i]+b[i];
            if(z==152) c+='T';
            else if(z==167) c+='E';
            else c+='S';
        }
    }
    return c;
}
int main() {
       lli n,b,ans=0,flag=0;
       cin>>b>>n;
       string temp,a1,a2,a3;
       map<string,int>y;
       string arr[b];
       FOR(i,b){
           cin>>arr[i];
           y[arr[i]]=1;
       }
       FOR(i,b-2){
           for(lli j=i+1;j<b-1;j++){
              temp=check(arr[i],arr[j]);
              if(y[temp]==1){
              for(lli k=j+1;k<b;k++){
                  if(temp.compare(arr[k])==0)ans++;
              } }
           }
       }
       cout<<ans<<endl;
    return 0;
}
