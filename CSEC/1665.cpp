#include<bits/stdc++.h>
#define int long long
using namespace std;
bool pos(int arr[],int n,int k,int mid){
    int sum=0,count=0;
    for(int i=0;i<n;++i){
        sum+=arr[i];
        if(sum>mid){
            count++;
            sum=arr[i];
        }
    }
    return count<=k;
}
int32_t main()
{
    int x,n;
	cin >> n >>x;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	int l=*max_element(arr,arr+n);
	int h=0;
	for(int i=0;i<n;i++)h+=arr[i];
	int ans=h;
	while(l<h){
	    int mid=l+(h-l)/2;
	    if(pos(arr,n,x,mid)){
	        ans=min(ans,mid);
	        h=mid-1;
	    }
	    else l=mid;
	}
	cout<<ans;
	return 0;
}