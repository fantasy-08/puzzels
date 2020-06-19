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
	vector<pair<int,int>>arr;
	for(int i=0;i<n;i++){
	    int t;
	    cin>>t;
	    arr.push_back({t,i});
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-2;i++){
	    int l=i+1,j=n-1;
	    while(l<j){
	        if(arr[i].first+arr[l].first+arr[j].first==x){
	            cout<<arr[i].second+1<<" "<<arr[l].second+1<<" "<<arr[j].second+1;
	            return 0;
	        }
	        if((arr[i].first+arr[l].first+arr[j].first)>x)j--;
	        else l++;
	    }
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}