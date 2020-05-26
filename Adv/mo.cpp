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

query Q[20001];
int arr[20001],ans[20001];
int fre[100001];
int cnt=0;

struct query{
    int l;
    int r;
    int i;
}
bool cmp(query A, query B){
    if(A.l/BLK!=B.l/BLK) return A.l/BLK < B.l/BLK;
    return A.r<B.r;
}

void add(int pos){
    fre[arr[pos]]++;
    if(fre[arr[pos]]==1) cnt++;
}

void remove(int pos){
    fre[arr[pos]]--;
    if(fre[arr[pos]]==0) cnt--;
}

void solve(){
    int n , q;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>ar[i];
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i = i , Q[i].l-- , Q[i].r--;
	}
	sort(Q , Q+q , comp);
	int ML = 0 , MR = -1;
	for(int i=0;i<q;i++)
	{
		int L = Q[i].l;
		int R = Q[i].r;
 
		while(ML > L)
		ML-- , add(ML);
 
		while(MR < R)
		MR++ , add(MR);
 
		while(ML < L)
		remove(ML) , ML++;
 
		while(MR > R)
		remove(MR) , MR--;
 
		ans[Q[i].i] = cnt;
	}
 
	for(int i=0;i<q;i++)
	cout<<ans[i]<<'\n';
    return;	
}


int32_t main() {
    fint{
        solve();
    }
    return 0;
}