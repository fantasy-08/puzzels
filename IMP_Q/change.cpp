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
int arr[3]={1,5,10},n=3,c=7;
lli go(){
    // if(change<0) return 0;
    // if(change==0) return 1;
    // lli sum=0;
    // FOR(i,n){
    //     if(arr[i]<=change){
    //         sum+=go(change-arr[i]);
    //     }
    // }
    lli a[c+1]={0};
    a[0]=1;
    FOR(i,n){
        rep(j,1,c+1){
            if(arr[i]<=j){
                a[j]+=a[j-arr[i]];
            }
        }
    }
    return a[c];
}
int main() {

    cout<< go()<<endl;
    return 0;
}
