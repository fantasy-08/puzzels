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
int main() {
    lli arr[12]={1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6},end_a=0,start_a=0 ;  
    mlli hash;
    FOR(i,12) hash[arr[i]]=9;
    FOR(i,12){
        if(hash[arr[i]]==1) continue;
        lli start=arr[i],end=arr[i];
        hash[arr[i]]=1;
        while(1){
            if(hash[start-1]==9){
            hash[start-1]=1;
            start-=1;
            }
            else{
                break;
            }
        }
        while(1){
            if(hash[end+1]==9){
            hash[end+1]=1;
            end+=1;
            }
            else{
                break;
            }
        }
        //cout<<end<<" "<<start<<endl;
        if(abs(end-start)>abs(end_a-start_a)){
            end_a=end;
            start_a=start;
        }
    }
    cout<<start_a<<" "<<end_a;
    return 0;
}
