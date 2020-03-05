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
lli s;
void sums(vector<lli> a){
    vector<pair<lli,lli>> ans;
    mlli h;
    FOR(i,a.size()) h[a[i]]+=1;
    sort(all(a));
    FOR(i,a.size()/2){
        if(h[s-a[i]] && s-a[i]!=s)
            ans.pb({a[i],s-a[i]});
        else if(h[s-a[i]]>1)
            ans.pb({a[i],a[i]});
    }
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }

}
int main() {
       cin>>s;
       lli n,temp;
       cin>>n;
       vlli l;
       FOR(i,n){
           cin>>temp,l.pb(temp);
       }
       sums(l);
    return 0;
}
