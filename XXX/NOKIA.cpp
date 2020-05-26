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
int main() {
    test{
        lli n,temp,sum=0,ind;
        cin>>n;
        vlli arr;
        FOR(I,n){
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end());
        FOR(i,n){
            if(arr[i]%2)temp=(arr[i]/2);
            else temp=arr[i]/2 -1;
            auto it=upper_bound(arr.begin(),arr.end(),temp);
            ind=it-arr.begin();
            sum+=(i-ind);
            //cout<<i<<"->"<<sum<<endl;
        }
        cout<<sum<<endl;
    
       }
    return 0;
}
