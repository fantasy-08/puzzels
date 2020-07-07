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
#define set(a,x) memset(a,x,sizeof(a));
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
using namespace std;
int main() {
    fint{
        map<lli,lli> check;
        vlli c,xx;
        lli n,temp,temp1,flag=0;cin>>n;
        lli arr[n],size=n;
        FOR(i,n){
            cin>>temp;
            arr[i]=temp;
            xx.pb(temp);
            check[temp]=1;
            if(temp>=2*n) flag=1;
        }
        if(flag){
            cout<<-1<<endl;
            continue;
        }
        FOR(i,2*n){
            if(check[i+1]==0) c.pb(i+1);
        }
        sort(all(c));
        // FOR(i,n) cout<<c[i]<<" ";
        // cout<<"o"<<endl;
        xx.clear();
    //    sort(all(xx));
        // while((flag==0) && (n>=0)){
        //     temp=c[n-1];
        //     temp2=xx[n-1];
        //     n-=1;
        //     c.pop_back();
        //     xx.pop_back();
        //     if(temp<temp2) flag=1;
        //     check[temp2]=temp;
        // }
        //cout<<"out";
        if(0) cout<<-1<<endl;
        else{
            FOR(i,size){
                // cout<<arr[i]<<" "<<check[arr[i]]<<" ";
                auto it=upper_bound(all(c),arr[i]);
                if(upper_bound(all(c),arr[i])==c.end()) {flag=1;break;}
                temp1=it-c.begin();
                xx.pb(arr[i]);xx.pb(c[temp1]);
                // cout<<arr[i]<<" "<<c[temp1]<<" ";
                c[temp1]=-1;
                sort(all(c));
            }
            // cout<<"over";
            if(flag) cout<<-1;
            else{
                // cout<<"hi";
                FOR(i,xx.size()) cout<<xx[i]<<" ";
            }
            cout<<endl;
        }

    }       
    return 0;
}
