
// Problem : Chef and Card Game
// Contest : CodeChef - July Challenge 2020 Division 2
// URL : https://www.codechef.com/JULY20B/problems/CRDGAME
// Memory Limit : 256 MB
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
int go(int a){
	int sum=0;
	while(a){
		sum+=a%10;
		a/=10;
	}
	return sum;
}

void solve(){
	int n;
	cin>>n;
	int chef=0,monty=0;
	while(n--){
		int a,b;
		cin>>a>>b;
		a=go(a);
		b=go(b);
		if(a==b) chef++,monty++;
		else if(a>b)chef++;
		else monty++;
	}
	if(chef>monty){
		cout<<0<<" "<<chef<<endl;
	}
	else if(monty>chef){
		cout<<1<<" "<<monty<<endl;
	}
	else{
		cout<<2<<" "<<chef<<endl;
	}
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
