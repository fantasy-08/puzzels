
// Problem : D. Decrease the Sum of Digits
// Contest : Codeforces - Codeforces Round #667 (Div. 3)
// URL : https://codeforces.com/contest/1409/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// God & me
// Fly ...
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
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define input(a,n) int n;cin>>n; SI(a,n)
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

void solve(){
	string s;
	int k;
	rd(s);
	rd(k);
	int sum=0;
	for(auto c:s)sum+=(c-'0');
	// pp(sum);
	if(sum<=k)pp(0);
	else
	{
		int carry=0;
// 		ans=0;
		string ans="";
		for(int i=s.size()-1;i>=0;i--)
		{
		   // cout<<i<<" "<<ans<<" "<<sum<<" "<<"----";
			if((s[i]-'0'+carry)==0){
				carry=0;
				ans='0'+ans;
				continue;
			}
			if((sum-(s[i]-'0'+carry-1))>k)ans=(char)(10-(s[i]-'0'+carry)+'0')+ans,sum=sum-(s[i]-'0')-carry+1,carry=1;
			else{
			   // cout<<ans<<" "<<endl;
				ans=(char)(10-(s[i]-'0'+carry)+'0')+ans;
				// cout<<10-(s[i]-'0'+carry)<<endl;
				// ans="0";
				int j=0;
				while(ans[j]=='0' && j<ans.size())j++;
				// pp(j);
				ans=(ans.substr(j));
				if(ans.size()==0)pp(0);
				else pp(ans);
				// pp("Done");
				return;
			}
			// cout<<sum<<endl;
			// cout<<(10-(s[i]-'0'+carry))*pow(10,s.size()-i-1)<<endl;
		}	
		int j=0;
		while(ans[j]=='0')j++;
		ans=(ans.substr(j));
		if(ans.size()==0)pp(0);
		else pp(ans);
	}
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
