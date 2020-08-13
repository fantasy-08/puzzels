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
#define MOD 1000000007
using namespace std;
string a,b;
vector<int>LPS(string p)
{
    int n=p.size();
    vector<int>ans(n,0);
    int i=1;
    ans[0]=0;
    int len=0;
    while(i<n)
    {
        if(p[i]==p[len])
        {
            ans[i]=++len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=ans[len-1];
            }
            else
            {
                ans[i]=0;
                i++;
            }
        }
    }
    return ans;
}

void solve(){
    cin>>a>>b;
    vector<int>lps;
    lps=LPS(a);
    int i=0,j=0,count=0;
    while(i<b.size())
    {
        if(a[j]==b[i])
        {
            i++;
            j++;
        }
        if(j==a.size())
        {
            count++;
            j=lps[j-1];
        }
        else if(a[j]!=b[i])
        {
            if(j!=0)j=lps[j-1];
            else i++;
        }
    }
    cout<<count<<endl;
	return;	
}


int32_t main() {
    // fint{
        fast;
    	solve();
    // }
    return 0;
}
