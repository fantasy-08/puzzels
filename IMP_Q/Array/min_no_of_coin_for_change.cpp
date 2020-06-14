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
int arr[3]={11,121,14},n=3,c=6;
lli go(lli change,lli req){
    lli minn=INT_MAX;
    if(change==0) return req;
    if(change<0) return INT_MAX;
    FOR(i,n){
        if(arr[i]<=change){
            minn=min(minn,go(change-arr[i],req+1));
        }
    }
    if(minn==INT_MAX )return -1;
    return minn;
}
int main() {

    cout<< go(c,0)<<endl;
    return 0;
}
