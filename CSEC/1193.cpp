
// Problem : Labyrinth
// Contest : CSES - CSES Problem Set
// URL : https://cses.fi/problemset/task/1193
// Memory Limit : 512 MB
// Time Limit : 1000 ms
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
int n,m,AA;
int arr[1001][1001];
string ans="";
pair<int,int>S,E;

void go(int i,int j,string s,int tot)
{
	if(i<0 || i>=n || j<0 || j>=m)return ;
	if(arr[i][j]==0){
		return ;
	}
	if(i==E.ft && j==E.se){
		ans=s;
		AA=tot;
		return ;
	}
	arr[i][j]=0;
	go(i+1,j,s+'D',tot+1);
	go(i,j-1,s+'L',tot+1);
	go(i-1,j,s+'U',tot+1);
	go(i,j+1,s+'R',tot+1);
}

void solve(){
	cin>>n>>m;
	FOR(i,n){
		FOR(j,m){
			char a;
			cin>>a;
			if(a=='#'){
				arr[i][j]=0;
			}
			else{
				arr[i][j]=1;
			}
			if(a=='A'){
				S={i,j};
			}
			if(a=='B'){
				E={i,j};
			}
		}
	}
	string useless="";
	go(S.ft,S.se,useless,0);
	if(ans.empty()){
		cout<<"NO";
		return ;
	}
	cout<<"YES\n";
	cout<<AA<<endl;	
	cout<<ans;
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}

