#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
bool solve(string a , string b){
	if(a == b)
	return true;
	ll n = a.size(), m = b.size();
	if(n != m || n%2 != 0 || m%2 != 0)
	return false;
 
	string a1="",a2="",b1="",b2="";
	
	for(ll i = 0; i < n/2; i++){
		a1 += a[i];
		a2 += a[n/2+i];
		b1 += b[i];
		b2 += b[n/2+i];
	}
 
	if((solve(a1, b1) && solve(a2, b2)) || (solve(a1, b2) && solve(a2, b1)) ){
		return true;
	}
	return false;       
}
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
	ll t;
	cin>>t;
 
	while(t--){
 
		string a, b;
		cin>>a>>b;
		if(solve(a, b))
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
}


// Condition for being OK :

// Any of the below is true:

// 1. Both the strings are equal.

// 2. Let's divide a into two contiguous segments a1 and a2. Similarly for b1 and b2. Either of 2.1 or 2.2 should hold.

//                 2.1 : pair (a1, b1) is OK AND pair(a2, b2) is OK.

//                 2.2 : pair (a1, b2) is OK AND pair(a2, b1) is OK.

// Note :- a1 and a2 should be of same length therefore b1 and b2 also.