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
lli check(lli arr[],lli x){
    if(arr[0]==0) return 0;
        lli tt=-1;
        lli lu,mx;
        lu=*min_element(arr,arr+x);
        mx=*max_element(arr,arr+x);
    if(lu!=0){
        if(lu==mx)
            return lu*x;
        FOR(i,x){
            if((arr[i]-lu)==0)
                    return (x)*lu+i;
        }
    }
    else{
        FOR(i,x) if(arr[i]==0) return (i);
    }
}
int main() {
      lli n,x,flag=0,temp,mex=1;
      cin>>n>>x;
      lli arr[x]={0};
      while(n--){
          cin>>temp;
          arr[temp%x]++;
          cout<<check(arr,x)<<endl;
      } 
    return 0;
}
