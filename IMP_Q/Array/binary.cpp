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
int binaryS(lli arr[],lli s,lli e,lli x){
    lli m=(s+e)/2;
    if(arr[m]==x)
        return m;
    if(arr[m]>x){
        return binaryS(arr,s,m-1,x);
    }
    else if(arr[m]<x){
        return binaryS(arr,m+1,e,x);
    }
    return -1;
}

int main() {
    lli arr[]={0, 1, 21, 33, 45, 45, 61, 71, 72, 73};
    cout<<binaryS(arr,0,9,33)<<endl;
    return 0;
}
