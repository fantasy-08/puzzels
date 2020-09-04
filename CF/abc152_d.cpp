
// Problem : D - Handstand 2
// Contest : AtCoder - AtCoder Beginner Contest 152
// URL : https://atcoder.jp/contests/abc152/tasks/abc152_d
// Memory Limit : 1024 MB
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
bool Chk(string a,string b)
{
	if(a[0]==b[b.size()-1] && a[a.size()-1]==b[0])return true;
	return false;	
}
int no(string a)
{
    int ans=0;
    for(int i=0;i<a.size();i++)
    {
        ans=ans*10+(a[i]-'0');
    }
    return ans;
}
void solve(){
	int n;
	rd(n);
// 	error(n);
	queue<pair<int,int>>q;
	map<pair<int,int>,bool>vis;	
	rep(i,1,10)
	{
		if(i<=n)
		{
			vis[{i,i}]=true;
			q.push({i,i});
		}
	}
	int ans=0;
	while(q.size())
	{
		auto Top=q.front();
		q.pop();
		int u=Top.ft,v=Top.se;
		if(Chk(to_string(u),to_string(v))==false)continue;
		ans++;
// 		cout<<u<<" "<<v<<endl;
		for(int i=0;i<=10;i++)
		{
			for(int j=0;j<=10;j++)
			{
				string U=to_string(u);
				string V=to_string(v);
				//Eight possiblities        !
				for(int l=0;l<3;l++)
				{
					for(int r=0;r<3;r++)
					{
						string U1,U2;
						if(l==0)U1=(char)('0'+i)+U;
						else if(l==1)U1=U+(char)('0'+i);
						else U1=U;
						if(r==0)U2=(char)('0'+j)+V;
						else if(r==1)U2=V+(char)('0'+j);
						else U2=V;
						int U_N=no(U1),V_N=no(U2);
						if((!Chk(U1,U2)) || (vis[{U_N,V_N}]))continue;
						if(U_N>n  ||  V_N>n)continue;
						vis[{U_N,V_N}]=true;
						q.push({U_N,V_N});
					}
				}
			}
		}
	}
	pp(ans);
// 	cout<<Chk("2","20");
	return;	
}


int32_t main() {
    fint{
    // 	fast;
    	solve();
    }
    return 0;
}
