#include <bits/stdc++.h>
#define FOR(i,n) for(long long int i=0;i<n;i++)
#define FORR(i,n) for(long long int i=n;i>=0;i--)
#define pb push_back
#define set(arr,x) memset(arr,x,sizeof(arr))
#define vlli vector<long long int>
#define slli set<long long int>
#define mlli map<long long int,long long int>
#define lli long long int 
#define test lli tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define MOD 1000000007
using namespace std;
bool ch[100006]={0};
//lli go()
int main() {
	   lli n,m,temp;
       cin>>n>>m;
       lli arr[n],dis[n]={0};
       FOR(i,n){
           cin>>arr[i];
       }
       dis[n-1]=1;
       ch[arr[n-1]]=1;
       FORR(i,n-2){
           if(ch[arr[i]]==0){
               dis[i]=dis[i+1]+1;
               ch[arr[i]]=1;
           }
           else{
               dis[i]=dis[i+1];
           }
       }
       FOR(i,m){
           cin>>temp;
           cout<<dis[temp-1]<<endl;
       }
    return 0;
}