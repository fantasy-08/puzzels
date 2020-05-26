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
string a,b;
lli min(lli a,lli b,lli c){
    lli temp=min(a,b);
    return min(temp,c);
}
lli go(){
    lli n1=a.size(),n2=b.size();
    lli arr[n1+1][n2+1];
    FOR(i,n2+1) arr[0][i]=i;
    FOR(i,n1+1) arr[i][0]=i;
    rep(i,1,n1+1){
        rep(j,1,n2+1){
            if(a[i]==b[j]) arr[i][j]=arr[i-1][j-1];
            else
            arr[i][j]=min(arr[i][j-1],arr[i-1][j],arr[i-1][j-1])+1;
        }
    }
    return arr[n1][n2];
}
int main() {
       cin>>a>>b;
    cout<<go()<<endl;
    return 0;
}
