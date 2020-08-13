
// Problem : A. Random Mood
// Contest : Codeforces - Matrix Exponentiation
// URL : https://codeforces.com/gym/102644/problem/A
// Memory Limit : 256 MB
// Time Limit : 250 ms
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

struct Matrix
{
	double a[2][2]={{0,0},{0,0}};
	Matrix operator *(const Matrix& other)
	{
		Matrix res;
		FOR(i,2)FOR(j,2)FOR(k,2)
		res.a[i][j]=(res.a[i][j]+(a[i][k])*(other.a[k][j]));
		return res;			
	}
};
Matrix power(Matrix A,int n)
{
	Matrix res;
	FOR(i,2)res.a[i][i]=1.0;
	while(n>0)
	{
		if(n&1)res=res*A;
		n/=2;
		A=A*A;
	}
	return res;
}


void solve(){
	double n,p;
	cin>>n>>p;
	Matrix Const;
	Error(n,p);
	Const.a[0][0]=1.0-p;
	Const.a[0][1]=p;
	Const.a[1][0]=p;
	Const.a[1][1]=1-p;
	Matrix Ans=power(Const,n);
	precision(6)
	cout<<(Ans.a[0][0]);
	/*for(int i=0;i<n;i++){
		H=happy*(1-p)+sad*p;
		S=happy*p+sad*(1-p);
	}	*/
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
