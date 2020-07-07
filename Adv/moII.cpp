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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define SI(a,n) int a[n];FOR(i,n) cin>>a[i];
#define SSI(a,n) int n;cin>>n; SI(a,n)
#define set(a,x) memset(a,x,sizeof(a))
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define ft first
#define se second
#define BLK 555
#define MOD 1000000007
using namespace std;

class Segment
{
private:
	int l[4*n+1],r[4*n+1],min[4*n+1],delta[4*n+1];
public:
	void init(int i,int a, int b){
		l[i]=a;
		h[i]=b;
		if(a==b) return ;
		int mid=a+(b-a)/2;
		init(2*i,a,mid);
		init(2*i+1,mid+1,b);
	}
	void increament(int a,int b,int val){
		increament(1,a,b,val);
	}
	void propogate(int i){
		delta[2*i]+=delta[i];
		delta[2*i+1]+=delta[i];
		delta[i]=0;
	}
	void update(int i){
		min[i]=min(min[2*i]+delta[2*i],min[2*i+1]+delta[2*i+1]);
	}
	void increament(int i,int a, int b, int val){
	//	|----| ||----|| |-----|
		if(b<l[i] || a>r[i]){
			return ;
		}
		if(l[i]>=a && r[i]<=b){
			delta[i]+=val;
		}
		//partial cover
		propogate(i);
		increament(2*i,a,b,val);
		increament(2*i+1,a,b,val);
		update(i);
	}
	int minimum(int a,int b){
		return minimum(1,a,b);
	}
	int minimum(int i,int a,int b){
		if(b<l[i] || a>r[i]){
			return INT_MAX;
		}
		if(l[i]>=a && r[i]<=b){
			return min[i]+delta[i];
		}
		propogate(i);

		int lMin=minimum(2*i,a,b);
		int rMin=minimum(2*i+1,a,b);

		update(i);

		return min(lMin,rMin);
	}

};



void solve(){
    return;	
}


int32_t main() {
    fint{
        solve();
    }
    return 0;
}