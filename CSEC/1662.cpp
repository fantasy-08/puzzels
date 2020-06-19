#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{
    int x,n;
	cin >> n ;
	int arr[n];
	map<int,int>f;
	int ans=0;
	f[0]=1;
	int sum=0;
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	    sum=(sum%n+arr[i]%n)%n;
	    if(sum<0){
	        sum=(sum+n)%n;
	    }
	    ans+=f[sum];
	    f[sum]++;
	}
	cout<<ans;
	return 0;
}