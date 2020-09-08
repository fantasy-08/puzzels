
// Problem : B. Password
// Contest : Codeforces - Codeforces Beta Round #93 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/126/B
// Memory Limit : 256 MB
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
vector<int> go(string s){
	int n=s.size();
	vector<int>lps(n);
	int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < n) { 
        if (s[i] == s[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    }
    return lps; 
}
bool pos(vector<int>lps,int len,int x){
	if(len==0)return false;
	FOR(i,lps.size()-1){
		if(lps[i]==len)return true;
	}
	return false;
}
void solve(){
	string s;
	rd(s);
	vector<int>a=go(s);	
	// for(auto v:a)cout<<v<<" ";
	// pp("");
	int max_pos=a[s.size()-1];
	if(max_pos==s.size()-1 && 0)cout<<s.substr(1);
	else if(pos(a,max_pos,1))cout<<s.substr(0,max_pos);
	else if(pos(a,a[a[a.size()-1]-1],2))cout<<s.substr(0,a[a[a.size()-1]-1]);
	else pp("Just a legend");	
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}

