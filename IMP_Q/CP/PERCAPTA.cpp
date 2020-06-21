
// Problem : Per Capita Income
// Contest : CodeChef - June Cook-Off 2020 Division 2
// URL : https://www.codechef.com/COOK119B/problems/PERCAPTA
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

int find(int par[],int n,int a){
    if(par[a]<0 || par[a]==a){
        return a;
    }
    return par[a]=find(par,n,par[a]);
}
void uni(int par[],int n,int a ,int b){
    int root_a=find(par,n,a);
    int root_b=find(par,n,b);
    if(abs(par[root_a])>abs(par[root_b])){
        par[root_a]+=par[root_b];
        par[root_b]=root_a;
    }
    else{
        par[root_b]+=par[root_a];
        par[root_a]=root_b;
    }
}
void solve(){
	int n,q;
	cin>>n>>q;
	vector<pair<int,pair<int,int>>>arr;
	int par[n+1];
	FOR(i,n+1){
		par[i]=-1;
	}
	vlli Arr(n),Popu(n);
	FOR(i,n)cin>>Arr[i];
	FOR(i,n){
		int t;
		cin>>t;
		Popu[i]=t;
		arr.pb({Arr[i],{t,i+1}});
	}
	sort(all(arr),[](pair<int,pair<int,int>>x,pair<int,pair<int,int>>y){
		return (x.ft*1.0)/(x.se.ft)>(y.ft*1.0)/(y.se.ft);
	});
	// ---
	vector<int>adj[n+1];
	while(q--){
		int u,v;
		cin>>u>>v;
		if(u>v)swap(u,v);
		uni(par,n,u,v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	mlli parent;
	map<int,double>capita;
	for(auto v:arr){
		double temp_inc=v.ft*1.0/v.se.ft;
		capita[v.se.se]=temp_inc;
	}
	map<int,vector<pair<int,int>>>same_path;
	for(int i=1;i<=n;i++){
		parent[i]=find(par,n,i);
		same_path[parent[i]].pb({i,capita[i]});
	}
	
	for(auto &vec:same_path){
		sort(all(vec.se),[&](pair<int,int>x,pair<int,int>y){
			if(x.se!=y.se)return x.se>y.se;			
			else if(Popu[x.ft-1]!=Popu[y.ft-1])return Popu[x.ft-1]<Popu[y.ft-1];
			return Arr[x.ft-1]>Arr[y.ft-1];
		});
	}	
	int ans_max=0;
	double ans_max_v=0;
	vlli Ans;
	for(auto v:same_path){
		int temp_pop=0;
		int temp_inc=0;
		FOR(i,v.se.size())
		{
			temp_pop+=Popu[v.se[i].ft-1];
			temp_inc+=Arr[v.se[i].ft-1];
			double capital=(temp_inc*1.0)/(temp_pop);
			if(capital>=ans_max_v && ans_max<i+1){
				ans_max_v=capital;
				ans_max=i+1;
				Ans.clear();
				FOR(j,i+1){
					Ans.pb(v.se[j].ft);
				}
			}
		}
	}
	cout<<ans_max<<endl;
	for(auto v:Ans)cout<<v<<" ";
	cout<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}
