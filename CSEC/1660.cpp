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
    int x,n;
	cin >> n >>x;
	int arr[n];
	map<int,int>f;
	int ans=0;
	f[0]=1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	    sum+=arr[i];
	    if(f.find(sum-x)!=f.end())ans+=f[-x+sum];
	    if(f.find(sum)==f.end())f[sum]=1;
	    else f[sum]++;
	}
	cout<<ans;
	return 0;
}