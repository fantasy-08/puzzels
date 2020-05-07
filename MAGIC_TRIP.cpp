//Q:https://practice.geeksforgeeks.org/problems/magic-triplets/0

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

int sum(int tree[],int n,int ind){
    int s=0;
    for(;ind>0;ind-=(ind&(-ind)))
        s+=tree[ind];
    return s;
}

void update(int tree[],int n,int ind,int val){
    for(;ind<=n;ind+=(ind&(-ind)))
        tree[ind]+=val;
}

void init(int arr[],int n){
    int temp[n];
    FOR(i,n)temp[i]=arr[i];
    sort(temp,temp+n);
    //UPDATE COMPLETE
    FOR(i,n){
        arr[i]=lower_bound(temp,temp+n,arr[i])-temp+1;
    }
}

int getCount(int arr[],int n){
    init(arr,n);
    int tree[n+1]={0};
    int g_r[n+1]={0};
    int s_l[n+1]={0};
    for(int i=n-1;i>=0;i--){
        g_r[i]=n-i-sum(tree,n,arr[i])-1;
        update(tree,n,arr[i],1);
    }
    FOR(i,n+1) tree[i]=0;
    FOR(i,n){
        s_l[i]=sum(tree,n,arr[i]-1);
        update(tree,n,arr[i],1);
    }
    int ans=0;
    FOR(i,n){
        ans+=g_r[i]*s_l[i];
    }
    return ans;
}



void solve(){
	int n;
	cin>>n;
	int arr[n];
	FOR(i,n)cin>>arr[i];
	cout<<getCount(arr,n)<<endl;
	return;	
}


int32_t main() {
    fint{
    	solve();
    }
    return 0;
}