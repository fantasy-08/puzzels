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
int st[1000000],arr[100000];
void build_tree(lli si,lli ss,lli se){
    if(ss==se) return st[si]=arr[se];
    lli mid=(ss+se)/2;
    build_tree(2*si,ss,mid);
    build_tree(2*si+1,mid+1,se);
    st[si]=min(st[2*si],st[2*si+1]);
}
lli query(lli si,lli ss,lli se,lli qs,lli qe){
    if(qs>se || qe<ss) return INT_MAX;
    if(ss>=qs && se<=qe) return st[si];
    lli mid=(ss+se)/2;
    lli l=query(2*si,ss,mid,qs,qe);
    lli r=query(2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}
int main() {
    fint{
        lli n;
        cin>>n;
        FOR(i,n) cin>>arr[i+1];
        lli q;cin>>q;
        build_tree(1,1,n);
        while(q--){
            lli t1,t2;cin>>t1>>t2; //0 based
            cout<<query(1,1,n,t1+1,t2+1)<<endl;
        }
    }   
    return 0;
}
