#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>> v(100005);
vector<pair<ll,ll>> arr;
vector<pair<pair<ll,ll>,pair<ll,ll>>> queries;

bool comp(pair<pair<ll,ll>,pair<ll,ll>> & a, pair<pair<ll,ll>,pair<ll,ll>> & b){
  return (a.first.first < b.first.first);
}

ll cnt =0 ,start[100005] ,stop[100005] , bit[200005],ans[100005],parent[20][100005] ,depth[100005],brr[100005];

void dfs(ll x,ll par){
    start[x] = ++cnt; depth[x] = 1+ depth[par]; parent[0][x] = par;
    for(auto k:v[x])
     if(par !=k) dfs(k,x);
    stop[x] = ++cnt;
}

ll lca (ll x ,ll y){
  if(depth[x]>depth[y]) swap( x, y);
    ll diff = depth[y] - depth[x];
 
    for(ll i=0;i<20;i++)
      if((diff>>i)& 1) y = parent[i][y];
    
    if(y==x) return y;
    for(ll i=19;i>=0;i--)
     if(parent[i][x]!=parent[i][y]) x = parent[i][x]  , y= parent[i][y];
 
    return parent[0][y];
}

void update(ll x,ll val){
   while(x<=cnt){
       bit[x] +=val; x +=(x&-x);
   }
}
 
ll query(ll x){
   ll res =0 ;
   while(x>0){
       res +=bit[x]; x -=(x & - x);
   }
   return res;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<n;i++){
    ll x,y; cin>>x>>y; v[x].push_back(y); v[y].push_back(x);
  }
  
  for(ll i=1;i<=n;i++){
    ll x; cin>>x; brr[i] = x;
    arr.push_back({x,i});
  }

  for(ll i=1;i<=m;i++){
    ll x,y,w; cin>>x>>y>>w;
    queries.push_back({{w,i},{x,y}});
  }

  depth[0] = 0; 
  memset(parent,-1,sizeof(parent));
  sort(arr.begin(),arr.end());
  sort(queries.begin(),queries.end(),comp);
  dfs(1,0);
  for(ll i=1;i<20;i++)
   for(ll j=1;j<=n;j++)
    if(parent[i-1][j]!=-1) parent[i][j] = parent[i-1][parent[i-1][j]];
   
   ll j=0;
   for(ll i=0;i<m;i++){
      ll a = queries[i].second.first , b =queries[i].second.second  , w =queries[i].first.first  ,index =queries[i].first.second ;
      while( j<n){
        if(arr[j].first>w)break;
        ll ind = arr[j].second , x = arr[j].first;
        update(start[ind],x) , update(stop[ind] , -x);
        ++j;
      }
      ll p = lca(a,b);
      ans[index] = query( start[a] ) + query(start[b]) - 2* query(start[p]);
      if(brr[p]<=w) ans[index] += brr[p];
   }  

   for(ll i=1;i<=m;i++) cout<<ans[i]<<"\n";
}
