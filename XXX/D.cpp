
// Problem : D. Monopole Magnets
// Contest : Codeforces - Codeforces Round #639 (Div. 2)
// URL : https://codeforces.com/contest/1345/problem/D
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
int n, m;
bool diff_b=0,diff_w=0,al_white=0,al_white_1=0;
int arr[1001][1001];
bool isCORR(){
	// row wise checked
	// cout<<"ROW CHECKING";
	FOR(i,n){
		int ind=-1;
		FOR(j,m){
			if(arr[i][j]==1 && ind==-1){
				ind=j;
			}
			else if(arr[i][j]==1){
				if(j==ind+1) ind=j;
				else{return false;}
			}
		}
		if(ind==-1) al_white=1; 
	}
	// cout<<"ROW CHECK";
	// colomn wise check
	FOR(j,m){
		int ind=-1;
		FOR(i,n){
			if(arr[i][j]==1 && ind==-1){
				ind=i;
			}
			else if(arr[i][j]==1){
				if(i==ind+1) ind=i;
				else return false;
			}
		}
		if(ind==-1 && al_white==0) al_white_1=1;
	}
	if(al_white==1 && al_white_1==0) return false;
	if(al_white==0 && al_white_1==1) return false;
	
	return true;
}
void dfs(int i,int j){
	if(i<0 || i>=n || j<0 || j>=m) return;
	if(arr[i][j]==0 || arr[i][j]==2) return;
	arr[i][j]=2;
	dfs(i+1,j);
	dfs(i-1,j);
	dfs(i,j+1);
	dfs(i,j-1); 
}
void solve(){
	cin>>n>>m;
	FOR(i,n){
		string s;
		cin>>s;
		FOR(j,m){
			if(s[j]=='#')arr[i][j]=1,diff_b=1;
			else arr[i][j]=0,diff_w=1;
		}
	}
	if(diff_b==0 || diff_w==0){
		if(diff_b){
			cout<<1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return ;
	}
	if(isCORR()){
		int count=0;
		FOR(i,n){
			FOR(j,m){
				if(arr[i][j]==1){
					count++;
					dfs(i,j);
				}
			}
		}
		cout<<count<<endl;
	}
	else cout<<-1<<endl;
	return;	
}


int32_t main() {
    
    solve();
    
    return 0;
}
