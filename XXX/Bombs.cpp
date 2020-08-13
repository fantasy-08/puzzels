
// Problem : C. Bombs
// Contest : Codeforces - Codeforces Round #203 (Div. 2)
// URL : https://codeforces.com/problemset/problem/350/C
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
#define plii pair< int,int >
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
int operation;
struct op
{
	int num;
	int dis;
	string dir;	
};
vector<op>Data;
void gotoP(int x1,int y1,int x2,int y2)
{
	int Xdis=x1-x2,Ydis=y1-y2;
	if(Xdis!=0)
	{
		operation++;
		op Temp;
		Temp.num=1;
		Temp.dis=abs(Xdis);
		if(Xdis<0)Temp.dir=" R";
		else Temp.dir=" L";
		Data.pb(Temp);
	}	
	if(Ydis!=0)
	{
		operation++;
		op Temp;
		Temp.num=1;
		Temp.dis=abs(Ydis);
		if(Ydis<0)Temp.dir=" U";
		else Temp.dir=" D";
		Data.pb(Temp);
	}
}


void solve(){
	int n;
	rd(n);
	vector<plii>points;
	FOR(i,n){
		int u,v;
		rd(u,v);
		points.pb({u,v});
	}	
	sort(all(points),[](plii x,plii y){
		if(x.ft<y.ft)return true;
		if(x.ft==y.ft)return x.se<y.se;
		return false;
	});
	int ind=0;
	operation=0;
	while(ind<n && points[ind].ft<0)ind++;
	if(ind!=n){
		for(int i=ind;i<n;i++){
			gotoP(0,0,points[i].ft,points[i].se);
			operation++;
			op Temp;
			Temp.num=2;
			Data.pb(Temp);
			gotoP(points[i].ft,points[i].se,0,0);
			operation++;
			Temp.num=3;
			Data.pb(Temp);
		}
	}
	if(ind!=0){
		ind--;
		while(ind>=0){
			gotoP(0,0,points[ind].ft,points[ind].se);
			op Temp;
			operation++;
			Temp.num=2;
			Data.pb(Temp);
			gotoP(points[ind].ft,points[ind].se,0,0);
			operation++;
			Temp.num=3;
			Data.pb(Temp);
			ind--;
		}
	}
	pp(operation);
	for(auto v:Data)
	{
		if(v.num==2)pp(2);
		else if(v.num==3) pp(3);
		else
		{
			cout<<1<<" "<<v.dis<<v.dir<<endl;
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
