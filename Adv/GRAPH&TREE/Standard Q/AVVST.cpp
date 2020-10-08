
// Problem : Avengers vs Thanos
// Contest : CodeChef - CODEZEN 2.0
// URL : https://www.codechef.com/CZEN2020/problems/AVVST
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// God & me
// Fly ...
//#pragma GCC optimize "trapv"//  WA to RE int!!

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<pll , null_type, less< pll >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define W while
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define fit(it,s) for(it=s.begin();it!=s.end();it++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mod 998244353
#define MAX 100005
#define M 32

using namespace std;
using namespace __gnu_pbds;

vector<vll> adj(300001);
ll h[300001],l[300001],r[300001],id[600005],a[300001],curr;
vll tree1(2400050),lazy(2400050);

void dfs(ll root,ll prev)
{
    ll i,j,k;
    l[root]=++curr;
    id[curr]=root;
    h[root]=h[prev]+1;
    k=adj[root].size();
    fn(i,k)
    {
        j=adj[root][i];
        if(j!=prev)
            dfs(j,root);
    }
    r[root]=++curr;
    id[curr]=root;
}

void push(ll node,ll s,ll e)
{
	if(lazy[node]!=0)
    {
        tree1[node]+=(e-s+1)*lazy[node];
        if(s!=e)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
void rangeupdate(ll node,ll s,ll e,ll l,ll r,ll inc)
{
	push(node,s,e);

    if(s>e || s>r || e<l)
        return;

    if(l<=s && e<=r)
    {
    	lazy[node]+=inc;
        push(node,s,e);
        return;
    }

    ll mid=(s+e)/2;
    rangeupdate(2*node,s,mid,l,r,inc);
    rangeupdate(2*node+1,mid+1,e,l,r,inc);

    tree1[node]=tree1[2*node]+tree1[2*node+1];
}
ll rangequery(ll node,ll s,ll e,ll l,ll r)
{
    if(s>e || s>r || e<l)
        return 0;

    push(node,s,e);

    if(l<=s && e<=r)
    {
    	return tree1[node];
    }

    ll mid=(s+e)/2;
    ll q=rangequery(2*node+1,mid+1,e,l,r);
    ll p=rangequery(2*node,s,mid,l,r);
    return p+q;
}

bool prime[300001]; 
void sieve(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    
    memset(prime, true, sizeof(prime)); 
    prime[0]=prime[1]=0;
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
          
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("in.txt","r",stdin);
    //freopen(2 "out.txt","w",stdout);

    ll t,n,i,u,v,c,q,z;
    sieve(300000);
    t=1;
    cin>>t;
    W(t--)
    {
        cin>>n>>q;
        fs(i,1,n+1)
        cin>>a[i];
        fn(i,n-1)
        {
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1,0);
        //sm(n);
        fs(i,1,n+1)
        {
        	if(a[i]>=2 && prime[a[i]]){
            rangeupdate(1,1,curr,l[i],l[i],1);
            rangeupdate(1,1,curr,r[i],r[i],1);}
        }
        W(q--)
        {
            cin>>c;
            if(c==1)
            {
            	cin>>u>>v;
            	if(a[u]>=2 && prime[a[u]])
            	{
            		rangeupdate(1,1,curr,l[u],l[u],-1);
            		rangeupdate(1,1,curr,r[u],r[u],-1);
            	}
            	if(v>=2 && prime[v])
            	{
            		rangeupdate(1,1,curr,l[u],l[u],1);
            		rangeupdate(1,1,curr,r[u],r[u],1);
            	
            	}
            	a[u]=v;
            }
            else
            {
                cin>>u;
                cout<<rangequery(1,1,curr,l[u],r[u])/2<<"\n";
            }
        }
        fn(i,n+1)
        {
        	adj[i].clear();
        	l[i]=r[i]=h[i]=a[i]=id[i]=0;
        	tree1[i]=lazy[i]=0;
        }
        fs(i,n+1,2*n+4)
        id[i]=tree1[i]=lazy[i]=0;
        fs(i,2*n+4,8*n+20)
        tree1[i]=lazy[i]=0;
        curr=0;
    }
    return 0;
}