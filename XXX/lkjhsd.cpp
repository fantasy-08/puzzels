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
string ss;
lli go(lli s,lli e){
    if(s==e || s>e || s+1==e) return 0;
    lli t1,t2;
    if(ss[s]==ss[e]){
        t1=1+go(s+1,e-1,val);
    }
    else if(ss[s]==ss[e-1] && ss[s+1]==ss[e]){
        t1= 2+go(s+2,e-2);
    }
    else t1=-1;
    return t1;

}
int main() {
       fint{
           lli n;
           lli hash[26]={0};
           char c;
           ss="";
           FOR(i,n){
               cin>>c;
               ss+=c;
               hash[c-'a']++;
           }
           lli odd=0;
           FOR(i,26) if(hash[i]&1) odd++;
           if(n&1==0 && odd!=0){
               cout<<"NO\n";
           }
           else if(odd!=1){
               {
                   cout<<"NO\n";
               }
           }
           else{
               if(go(0,n-1)>=0){
                   cout<<"YES\n";
                   cout<<go(0,n-1)<<endl;
               }
               else{
                   cout<<"NO\n";
               }
           }
       }
    return 0;
}
