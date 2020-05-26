#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(lli i=(lli)a;i<=(lli)b;i++)
#define FORR(i,a,b) for(lli i=(lli)a;i>=(lli)b;i--)
#define f first
#define s second
#define inf Q0000001
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sz(a) (lli)(a).size()
typedef long long int lli;
typedef vector< lli > vlli;
typedef pair<lli,lli> plli;
typedef unordered_set<lli> slli;
typedef unordered_map<lli,lli> mlli;
 
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {lli idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
 
//*****************************************************************
lli cal(lli a,lli b,lli c,lli d,string&S )
{
	lli a1=0;
	lli b1=0;
	lli c1=0;
	FOR(i,0,S.size()-1)
	{
		if(S[i]=='V')
			a1++;
		else if(S[i]=='K')
			b1++;
		else
			c1++;
		switch(d)
		{
			case 0:{
				if(a1==a+1)
					return max(b1-b,(lli)0)+max(c1-c,(lli)0);
				break;
			}
			case 1:{
				if(b1==b+1)
					return max(a1-a,(lli)0)+max(c1-c,(lli)0);
				break;
			}
			default :{
				if(c1==c+1)
					return max(a1-a,(lli)0)+max(b1-b,(lli)0);
				break;
			}
		}
	}
}

int main()
{
	fastio
	lli n;
	cin>>n;
	string S;
	cin>>S;
	vlli V(3,0);
	FOR(i,0,n-1)
	{
		if(S[i]=='V')
			V[0]++;
		else if(S[i]=='K')
			V[1]++;
		else
			V[2]++;
	}
	vector<vector<vector<vlli > > > D(V[0]+1, vector< vector<vlli > >( V[1]+1, vector<vlli >( V[2]+1, vlli(2,0))));
	
	FOR(i,0,V[0])
	{
		FOR(j,0,V[1])
		{
			FOR(k,0,V[2])
			{
				if(!(i==0&&j==0&&k==0))
				FOR(m,0,1)
				{
					lli mini=INT_MAX;
					if(m==0)
					{
						if(j!=0)
							mini = min(mini,cal(i,j-1,k,1,S) + D[i][j-1][k][0]);
						if(k!=0)
							mini = min(mini,cal(i,j,k-1,2,S) + D[i][j][k-1][0]);
						if(k!=0)
							mini = min(mini,cal(i,j,k-1,2,S) + D[i][j][k-1][1]);
					}
					else 
					{
						if(i!=0)
							mini = min(mini,cal(i-1,j,k,0,S) + D[i-1][j][k][0]);
						if(i!=0)
							mini = min(mini,cal(i-1,j,k,0,S) + D[i-1][j][k][1]);
					}
					// if(mini!=INT_MAX)
						D[i][j][k][m]=mini;
					// cout<<i<<" "<<j<<" "<<k<<" "<<m<<" "<<D[i][j][k][m]<<endl;
				}
			}
		}
	}
	cout<<min(D[V[0]][V[1]][V[2]][0],D[V[0]][V[1]][V[2]][1])<<endl;
	// pr(D);
	return 0;
}