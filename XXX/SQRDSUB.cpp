// Think nlogn 
//DONE n^2 to n
// Problem : Squared Subsequences
// Contest : CodeChef - April Challenge 2020 Division 1
// URL : https://www.codechef.com/APRIL20A/problems/SQRDSUB
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

void solve(){
	lli n,cont,index=0;
	cin>>n;
	lli arr[n];
	FOR(i,n) cin>>arr[i];
	lli even[n],help[n],pos=-1;
	lli ans=0;
	rep(i,0,n){
		if(arr[i]&1){
			even[i]=0;
			help[i]=pos;	
			ans++;
		} 
		else{
			if(arr[i]%4==0) even[i]=2,ans++;
			else even[i]=1;
			help[i]=pos;
			pos=i;
		}
		
	}
	while(index<n){
		cont=0;
		if(arr[index]&1){
			rep(i,index,n){
				if(arr[i]&1) cont++;
				else break;
			}
			ans+=(cont*(cont-1))/2;
			index=index+cont;
		}
		else index++;
	}
	rep(i,0,n){
		if(even[i]==2){
			ans+=i;
		}
		else if(even[i]==0 && help[i]==-1) continue;
		else if(even[i]==1 && help[i]==-1) continue;
		else if(even[i]==0){
			cont=help[help[i]];
			index=even[help[i]];
			if(index==2){
				ans+=help[i]+1;
				continue;
			}
			if(cont==-1) continue;
			else{
				ans+=cont+1;
			}
		}
		else{
			cont=help[i];
			ans+=cont+1;
		}
	}
	cout<<ans<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
