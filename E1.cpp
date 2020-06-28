
// Problem : E1. Reading Books (easy version)
// Contest : Codeforces - Codeforces Round #653 (Div. 3)
// URL : https://codeforces.com/contest/1374/problem/E1
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
	int n,k;
	cin>>n>>k;
	int arr[n];
	vlli a,b;
	// vlli ans;
	vlli common;
	set<int>CC;
	// vector<pair<int,pair<int,int>>>Arr;
	FOR(i,n){
		cin>>arr[i];
		int A,B;
		cin>>A>>B;
		// cerr<<arr[i]<<" "<<A<<" "<<B<<endl;
		// Arr.pb({arr[i],{A,B}});
		if(A && B){
			common.pb(i);
			CC.insert(i);
			continue;
		}
		if(A)
			a.pb(i);
		else if(B)
			b.pb(i);
	}
	// sort(all(Arr),[](pair<int,pair<int,int>>a,pair<int,pair<int,int>>b){
		// return a.ft<b.ft;
	// });
	// int x=0,y=0;
	// int time=0;
	// for(auto v:Arr){
		// if(v.se.ft==1 && v.se.se==1){
			// time+=v.ft;
			// x++,y++;
		// }
		// else if(x>=k){
			// if(v.se.se){
				// time+=v.ft;
				// y++;
			// }
		// }
		// else if(y>=k){
			// if(v.se.ft){
				// time+=v.ft;
				// x++;
			// }
		// }
		// else{
			// if(v.se.se){
				// time+=v.ft;
				// y++;
			// }
			// if(v.se.ft){
				// time+=v.ft;
				// x++;
			// }
		// }
		// if(x>=k && y>=k)break;
	// }
	// if(x>=k && y>=k)cout<<time<<endl;
	// else cout<<-1;
	sort(all(a),[&](int a,int b){
		return arr[a]<arr[b];
	})	;
	sort(all(b),[&](int a,int b){
		return arr[a]<arr[b];
	})	;
	sort(all(common),[&](int a,int b){
		return arr[a]<arr[b];
	})	;
	// error(a.size());
	int A=0,B=0;
	vlli takena;
	int time=0;
	for(auto v:a){
		A++;
		takena.pb(v);
		// time+=arr/[v];
		if(A==k)break;
	}
	vlli takenb;
	for(auto v:b){
		B++;
		takenb.pb(v);
		// time+=arr[v];
		if(B==k)break;
	}
	
	if(takena.size()+common.size()<k){
		cout<<-1<<endl;
		return ;
	}
	else if(takenb.size()+common.size()<k){
		cout<<-1<<endl;
		return ;
	}
	
	int x=takena.size()-1;
	int y=takenb.size()-1;
	 // Error(x,y);
	FOR(i,takena.size())time+=arr[takena[i]];
	FOR(i,takenb.size())time+=arr[takenb[i]];
	// error(time);
	if(takena.size()!=k){
		B=0;
		A=k-takena.size();
		// if(B>=common.size())break;
		while(A--)
		{
			if(B>=common.size())break;
			time+=arr[common[B]];
			takenb.pb(common[B]);
			takena.pb(common[B++]);
		}
	}
	// error(y);
	// error(B);
	//take from B
		 // Error(takena.size(),takenb.size());
	if(takenb.size()!=k){
		A=k-takenb.size();
		
		while(A--)
		{	
			// error(B);
			if(B>=common.size())break;
			// error(A);
			time+=arr[common[B]];
			// error(B);
			takena.pb(common[B]);
			// x=B;
			takenb.pb(common[B++]);
		}
	}
	// error(time);
	// Error(takena.size(),takenb.size());
	 // Error(x,y);
	if(takena.size()>k){
		int buf=takena.size()-k;
		while(buf-- && x>=0){
			time-=arr[takena[x--]];
		}
	}
	if(takenb.size()>k){
		int buf=takenb.size()-k;
		while(buf-- && x>=0){
			time-=arr[takenb[y--]];
		}
	}
	 // Error(x,y);
	// error(time);
	if(x==-1 || y==-1)
	cout<<time;
	else{
		while(x>=0 && y>=0 && B<common.size() && arr[takena[x]]+arr[takenb[y]]>arr[common[B]]){
			time=time-(arr[takena[x]]+arr[takenb[y]])+(arr[common[B]]);
			x--,y--;
			B++;
		}
		cout<<time;
	}
	
	return;	
}


int32_t main() {
    // fint{
    	fast;
    	solve();
    // }
    return 0;
}
