#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define clr(x) memset(x,0,sizeof(x))
#define FOR(i,n) for(lli i=0;i<n;i++)
#define vi vector<int>
#define vl vector<long>
#define pb push_back
#define tt lli T;cin>>T;while(T--)
#define mi unordered map<int ,int >
#define ft first
#define sd second
int main() {
    tt
    {
        lli arr[3],ans;
        set<lli>a;
        FOR(i,3){cin>>arr[i];a.insert(arr[i]);}
        if(a.size()==1)cout<<0<<endl;
        else if(a.size()==3){
            sort(arr,arr+3);
            arr[0]+=1;arr[2]-=1;
            ans=abs(arr[2]-arr[1])+abs(arr[1]-arr[0])+abs(arr[2]-arr[0]);
            cout<<ans<<endl;
        }
        else{
            sort(arr,arr+3);
            if(abs(arr[2]-arr[0])==1)cout<<0<<endl;
            else{
                if(arr[1]==arr[0])
                {arr[2]-=1;
                arr[1]++;
                arr[0]++;}
                else{
                arr[2]-=1;
                arr[1]--;
                arr[0]++;
                }
                ans=abs(arr[2]-arr[1])+abs(arr[1]-arr[0])+abs(arr[2]-arr[0]);
                cout<<ans<<endl;
            }
           // cout<<"->";
        }

        
	}
	return 0;
}
 