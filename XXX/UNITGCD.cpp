
// Problem : Unit GCD
// Contest : CodeChef - April Challenge 2020 Division 2
// URL : https://www.codechef.com/APRIL20B/problems/UNITGCD
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
#define FOR(i,n) for(long long int i=0;i<n;i++)
#define FORR(i,n) for(long long int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<long long int>
#define slli set<long long int>
#define mlli map<long long int,long long int>
#define lli long long int 
#define test lli tt1234; cin>>tt1234;while(tt1234--)
#define endl "\n"
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
using namespace std;
map<lli,vlli> f;
set<lli >common;
void insert_fact(lli n){
	for(lli val:f[n]) common.insert(val);
}
void fact(){
	f[1].pb(1);
	rep(i,2,100001){
		lli temp=i;
		if(temp%2==0) f[i].pb(2);
		while(temp%2==0){
			temp/=2;
		}
		for(lli j=3;j<=sqrt(temp);j+=2){
			if(temp%j==0) f[i].pb(j);
			while(temp%j==0) temp/=j;			
		}
		if(temp>2) f[i].pb(temp);
	}
		// for(auto cc:f[3]) cout<<cc<<"-";
}
void solve(){
	lli n;
	cin>>n;
	bool arr[n+1];
	set(arr,false);
	vector<vlli> days;
	lli day=0;
	while(1){
		common.clear();
		int flag=-1;
		rep(i,1,n+1){
			if(arr[i]==false){
				flag=i;
				break;
			}
		}
		if(flag==-1) break;
		vlli temp;
		temp.pb(flag);
		arr[flag]=true;
		insert_fact(flag);
		rep(i,flag+1,n+1){
			if(arr[i]==false){ 
				int flag2=0;
				for(lli ff:f[i]){
					if(common.find(ff)!=common.end()){flag2=1;break;}
				}
				if(flag2==0){
					temp.pb(i);
					arr[i]=true;
					insert_fact(i);
				}
			}
		}
		if(temp.size()==1) temp.pb(1);
		day++;
		common.clear();
		days.pb(temp);
	}
	cout<<days.size()<<endl;
	for(auto x:days){
		for(auto m:x) cout<<m<<" ";
		cout<<endl;
	}
	return;	
}


int32_t main() {
	fact();
    fint{
    	solve();
    }
    return 0;
}
