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
	   cout<<"HELLO";
       lli n,m;
       cin>>n>>m;
       string t1,t2;
       map<string,string> ans;
       FOR(i,m){
           cin>>t1>>t2;
           if(t1.size()<=t2.size()) t2=t1;
           ans[t1]=t2;
       }
       FOR(i,n){
           cin>>t1;
           cout<<ans[t1]<<" ";
       }
    return 0;
}