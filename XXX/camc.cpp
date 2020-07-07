#include <iostream.h>
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
	      lli n,m;
	      cin>>n>>m;
	      lli arr[n],lar=INT_MIN,min=INT_MAX,ans=0,arr2[n],ll;
	      map<lli,lli> color,res;
	      //set<lli> ss;
	      FOR(i,n){
	          cin>>arr2[i];
	          arr[i]=arr2[i];
	          res[arr[i]]=i%m;
	           }
	       sort(arr,arr+n);
	       lli final[m]={0},count=0;
	       FOR(i,n){
	           if(count==m)break;
	           if(final[res[arr[i]]]==0){
	               final[res[arr[i]]]=arr[i];count++;
	               if(arr[i]>lar)lar=arr[i];
	               if(arr[i]<min)min=arr[i];
	           }
	       }
	       ans=lar-min;
	       //FOR(i,m)cout<<final[i]<<" ";
	       //cout<<endl<<ans<<endl;
	       FOR(i,n){
	       	if(final[res[arr[i]]]!=arr[i]){
			   final[res[arr[i]]]=arr[i];
			   lar=*max_element(arr,arr+m);
			   min=*min_element(arr,arr+m);
			   if(ans>(lar-min))ans=lar-min;
	           
	       }
	       }
	       
	       
	       cout<<ans<<endl;
	     
	  } 
    return 0;
}

