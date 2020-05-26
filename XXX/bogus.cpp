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
lli n,m;
lli ans(lli i,lli j,lli count){
    if((i==n-1) && (count&1)){
        if(j>=0 && j<=m-1){
            //cout<<i<<j<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(i==n-1) return 0;
    else if((i>=n) || (j>=m)) return 0;
    else if((i<0) || (j<0)) return 0;
    return (ans(i+2,j+1,count+1)%MOD)+(ans(i+1,j+2,count+1)%MOD)+(ans(i+2,j-1,count+1)%MOD)+(ans(i+1,j-2,count+1)%MOD);
}
   
int main() {
	 cin>>n>>m;
	 lli temp=0;
	 for(lli i=1;i<m;i+=2){
	     temp+=(ans(0,i,0)%MOD);
	 }
	 cout<<temp<<endl;
    return 0;
}
