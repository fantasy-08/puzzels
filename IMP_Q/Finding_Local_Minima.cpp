
// Problem : C. Searching Local Minimum
// Contest : Codeforces - Codeforces Round #700 (Div. 2)
// URL : https://codeforces.com/contest/1480/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(i,n) for(int i=n;i>=0;i--)
#define pb push_back
#define vint vector<int>
#define sint set<int>
#define mint map<int,int>
#define pint pair< int,int >
#define int long long int 
#define test int tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define input(a,n) int n;cin>>n;vint a(n);for(int&v:a)rd(v);
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define precision(x) cout<<fixed<<setprecision(x);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define present(container, element) (container.find(element)!=container.end())
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define MOD 1000000007
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }
bool isMax(int mid,vint& arr)
{
	if(arr[mid]==-1)
	{
		cout<<"? "<<mid<<endl;
		cout.flush();
		cin>>arr[mid];
		cout.flush();
	}
	if(arr[mid-1]==-1)
	{
		cout<<"? "<<mid-1<<endl;
		cout.flush();
		cin>>arr[mid-1];
		cout.flush();
	}
	if(arr[mid+1]==-1)
	{
		cout<<"? "<<mid+1<<endl;
		cout.flush();
		cin>>arr[mid+1];
		cout.flush();
	}
	
	if(arr[mid]<arr[mid-1] && arr[mid]<arr[mid+1]){
		return true;
	}
	return false;
}
void solve(){
	int n;
	cin>>n;
	cout.flush();
	
	int l=1,r=n;
	vector<int>arr(n+2,-1);
	arr[0]=n+1,arr[n+1]=n+1;
	while(l<=r)
	{
		if(l==r)
		{
			cout<<"! "<<l<<endl;
			cout.flush();
			return ;
		}
		else if((r-l+1)==2)
		{
			if(isMax(r,arr)){
				cout<<"! "<<r<<endl;
				cout.flush();
				return ; 
			}
			else 
			{
				cout<<"! "<<l<<endl;
				cout.flush();
			}
			return ;				
		}
		else
		{
			int mid=l+(r-l)/2;			
			if(isMax(mid,arr)){
				cout<<"! "<<mid<<endl;
				cout.flush();
				return ; 
			}
			else if(arr[mid-1]>arr[mid]){
				r=mid-1;
			}
			else l=mid+1;
		}
	}
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
