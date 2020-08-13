
// Problem : C. Fibonacci
// Contest : Codeforces - Matrix Exponentiation
// URL : https://codeforces.com/gym/102644/problem/C
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
#define Vo vector<vector<int>>
using namespace std;
template<typename... T> void rd(T&... args) { ((cin >> args), ...); }
template<typename... T> void pp(T... args) { ((cout << args << " "), ...); cout<<"\n"; }

struct Matrix
{
	int a[2][2]={{0,0},{0,0}};
	Matrix operator *(const Matrix& other)
	{
		Matrix res;
		FOR(i,2)FOR(j,2)FOR(k,2)
		res.a[i][j]=(res.a[i][j]%MOD+(a[i][k]%MOD)*(other.a[k][j]%MOD))%MOD;
		return res;			
	}
};
Matrix power(Matrix A,int n)
{
	Matrix res;
	FOR(i,2)res.a[i][i]=1;
	while(n>0)
	{
		if(n&1)res=res*A;
		n/=2;
		A=A*A;
	}
	return res;
}


void solve(){
	int n;
	rd(n);
	if(n==0){
		pp(0);
		return ;
	}
	Matrix Const;
	Const.a[0][0]=0;
	Const.a[0][1]=1;
	Const.a[1][0]=1;
	Const.a[1][1]=1;
	Matrix Ans=power(Const,n-1);
	int f=0,s=1;
	int A=f*Ans.a[0][0]+s*Ans.a[1][0];
	int B=f*Ans.a[0][1]+s*Ans.a[1][1];
	pp(B);
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
