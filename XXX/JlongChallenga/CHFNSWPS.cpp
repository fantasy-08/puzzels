
// Problem : Chefina and Swaps
// Contest : CodeChef - July Challenge 2020 Division 2
// URL : https://www.codechef.com/JULY20B/problems/CHFNSWPS
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#pragma GCC optimize "trapv"//  WA to RE int!!
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
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
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
	mlli t,a,b;
	int n;
	cin>>n;
	int mini=INT_MAX;
	FOR(i,n){
		int T;
		cin>>T;
		mini=min(mini,T);
		t[T]++;
		a[T]++;
	}
	FOR(i,n){
		int T;
		cin>>T;
		mini=min(mini,T);
		t[T]++;
		b[T]++;
	}
	for(auto v:t){
		if(v.se&1){
			cout<<-1<<endl;
			return ;
		}
	}
	vlli sa,sb;
	for(auto v:t){
		int x=v.se/2;
		if(a[v.ft]>x){
			int rem=(a[v.ft]-x);
			while(rem--)sa.pb(v.ft);
		}
		else if(b[v.ft]>x){
			int rem=(b[v.ft]-x);
			while(rem--)sb.pb(v.ft);
		}
	}
	if(sa.empty()){
		cout<<0<<endl;
		return ;
	}
	sort(all(sa));
	sort(all(sb)); 
	// int flag=0;
	reverse(all(sb));
	int ans=0;
	FOR(i,sa.size())ans+=min(min(sa[i],sb[i]),2*mini);
	cout<<ans<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
