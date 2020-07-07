
// Problem : C. Social Distance
// Contest : Codeforces - Codeforces Round #650 (Div. 3)
// URL : https://codeforces.com/contest/1367/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<int>
#define slli set<int>
#define mlli map<int,int>
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define present(container, element) (container.find(element)!=container.end())
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	vector<int>ind;
	string s;
	cin>>s;
	FOR(i,n){
		if(s[i]=='1'){
			ind.pb(i);
		}
	}
	int i=0;
	int ans=0;
	if(ind.size()==n){
		cout<<0<<endl;
		return ;
	}
	if(ind.size()==0)
	{
		int i=0;
		while(i<n){
			ans++;
			i+=(k+1);
		}
		cout<<ans<<endl;
		return ;
	}
	while(i<n)
	{
		if(binary_search(all(ind),i)){
			i+=k+1;
			continue;
		}
		int x=i+k;
		int l=0,h=ind.size()-1;
		bool pos=false;
		while(l<=h)
		{
			int mid=(l)+(h-l)/2;
			if(ind[mid]<=x && ind[mid]>i)
			{
				pos=true;
				break;
			}
			if(ind[mid]>x)h=mid-1;
			else l=mid+1;
		}
		if(pos==true){
			i++;
		}	
		else{
			ans++;
			i+=k+1;
		}
		
	}
	cout<<ans<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
