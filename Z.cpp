
// Problem : Perfect Power Divisors
// Contest : CodeChef - April Challenge 2020 Division 1
// URL : https://www.codechef.com/APRIL20A/problems/PPDIV
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

map<lli,lli>dp;


void solve(){
	lli n=1000000;
	lli i=1;
	lli ans=0,count=0;;
	rep(ind,1,n+1){
		if(dp[ind]!=0) {ans+=dp[ind];}
		else{
			set<lli>keniya;
			i=2;
			count=1;
			while(i<=sqrt(ind)){
				int k=i*i;
				while(k<=ind){
					// error(k);
					if(ind%k==0){ keniya.insert(k);}
					k*=i;
				}
				i++;
			}
			for(lli v:keniya) count+=v;
			ans+=count;
			if(ans>MOD) ans-=MOD;
			dp[ind]=count;
		}
		i++;
		if(ans>MOD) ans-=MOD;		
	}
	if(ans>MOD) ans-=MOD;
	// FOR(i,24){cerr<<i<<" ";error(dp[i]);}
	rep(i,1,1000001) cout<<dp[i]<<",";
	return;	
}


int32_t main() {
	dp[1]=1;dp[2]=1;dp[3]=1;dp[4]=5;
    fint{
    	solve();
    }
    return 0;
}

