
// Problem : Chef and Dragon Dens
// Contest : CodeChef - July Challenge 2020 Division 2
// URL : https://www.codechef.com/JULY20B/problems/DRGNDEN
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
int n,q;
vector<int>h,p,hr,pr;

int tree[800005];

void build(int ind,int s,int e)
{
	if(s==e)
	{
		tree[ind]=h[s];
		return;
	}
	int mid=s+(e-s)/2;
	build(2*ind,s,mid);
	build(2*ind+1,mid+1,e);
	tree[ind]=max(tree[2*ind],tree[2*ind+1]);
}

int query(int ind,int ss,int se,int qs,int qe)
{
	if(ss>=qs && se<=qe)
	{
		return tree[ind];
	}
	if(se<qs || ss>qe)return 0;
	int mid=ss+(se-ss)/2;
	int l=query(2*ind,ss,mid,qs,qe);
	int r=query(2*ind+1,mid+1,se,qs,qe);
	return max(l,r);
}





int solve_inc(int l,int e)
{
	int ans=p[l];
	int prev=l;
	for(int i=l+1;i<e+1;i++)
	{
		if(h[i]>h[prev])
		{
			ans+=p[i];
			prev=i;
		}
	}
	if(prev!=e)return -1;
	return ans;	
}
int solve_dec(int e,int l)
{
	int ans=p[e];
	int prev=e;
	for(int i=e-1;i>=l;i--)
	{
		if(h[i]>h[prev]){
			ans+=p[i];
			prev=i;
		}
	}
	if(prev!=l)return -1;
	return ans;	
}
void solve(){
	cin>>n>>q;
	h.resize(n+1,0);
	// h2.resize(n+1,0);
	p.resize(n+1,0);
	FOR(i,n){
		int t;
		cin>>t;
		h[i+1]=(t);
	}
	FOR(i,n){
		int t;
		cin>>t;
		p[i+1]=t;
	}
	build(1,1,n);
	vector<int>nextG(n+1,0),nextrG(n+1,0);
	stack<int>s;
	for(int i=n;i>=1;i--)
	{
		while(!s.empty() && h[s.top()]<=h[i])s.pop();
		if(s.empty())nextG[i]=-1;
		else nextG[i]=s.top();
		s.push(i);
	}
	while(!s.empty())s.pop();
	for(int i=1;i<=n;i++)
	{
		while(!s.empty() && h[s.top()]<=h[i])s.pop();
		if(s.empty())nextrG[i]=-1;
		else nextrG[i]=s.top();
		s.push(i);
	}
	// for(auto v:nextrG)cerr<<v<<" ";
	while(q--)
	{
		int choice;
		cin>>choice;
		if(choice==1)
		{
			int ind,x;
			cin>>ind>>x;
			p[ind]=x;
		}
		else
		{
			int st,en;
			cin>>st>>en;
			if(st==en){
				pp(p[st]);
			}
			else if(en>st)
			{
				if(h[en]>=h[st]){
					pp(-1);
				}
				else{
					// Error(st,en);
					// error(query(1,0,n-1,st,en));
					if(query(1,1,n,st,en)!=h[st]){
						pp(-1);
						continue;
					}
					int ans=p[en];
					int curr=nextrG[en];
					while(curr>st && curr!=-1)
					{
						ans+=p[curr];
						curr=nextrG[curr];
					}
					if(curr==st)
					{
						ans+=p[curr];
						pp(ans);
					}			
					else pp(-1);		
				}
			}
			else{
				swap(st,en);
				
				// error(query(1,0,n-1,st,en));
				if(query(1,1,n,st,en)!=h[en]){
					pp(-1);
					continue;
				}
				if(h[en]<=h[st]){
					pp(-1);
				}
				else{
					// if(query)
					int ans=p[st];
					int curr=nextG[st];
					while(curr<en && curr!=-1)
					{
						ans+=p[curr];
						curr=nextG[curr];
					}
					if(curr==en)
					{
						ans+=p[curr];
						pp(ans);
					}			
					else pp(-1);		
				}
			}	
		}
	}
	return;	
}


int32_t main() {
	fast;
	solve();
    return 0;
}

/*
void update(int ind,int ss,int se,int pos,int val)
{
	if(ss==se)
	{
		arr[pos]=val;
		tree[ind]=val;
		return ;
	}
	int mid=ss+(se-ss)/2;
	if(ss<=pos && pos<=mid)
		update(2*ind,ss,mid,pos,val);
	else
		update(2*ind+1,mid+1,se,pos,val);
	tree[ind]=tree[2*ind]+tree[2*ind+1];
}

*/
