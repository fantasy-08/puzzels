#include<bits/stdc++.h>
#define int long long
using namespace std;

bool pos(int arr[],int n,int x,int mid){
    int tot=0;
    for(int i=0;i<n;i++){
        tot+=(mid/arr[i]);
    }
    return tot>=x;
}


int32_t main()
{
    int n,x;
	cin >> n >> x;
	int arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	int l=0,h=(*min_element(arr,arr+n))*x;
	int ans=h;
	while(l<=h){
	    int mid=l+(h-l)/2;
	    if(pos(arr,n,x,mid)){
	        ans=mid;
	        h=mid-1;
	    }
	    else l=mid+1;
	}
	cout<<ans;
	return 0;
}