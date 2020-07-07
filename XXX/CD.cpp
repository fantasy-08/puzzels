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
#define MOD 1000000007
using namespace std;
  
   
int main() {
	 for(lli ii=20;ii<82;ii++){
	     lli n,power,ans=0,y,zz,t1;
	     n=ii;
	     power=(log(n))/log(3);//cout<<power;
	     zz=n;
	     if(n<3)                {cout<<n<<endl;continue;}
	     vlli po,cnt;
         //cout<<zz/(pow(3,power));
         while (zz>0){
             t1=zz/(pow(3,power));//t1++;
             zz=zz-(t1*(pow(3,power)));
             po.pb(power);
             cnt.pb(t1);
             power--;
         }
         cout<<ii<<"--->\n";
         FOR(i,po.size())cout<<po[i]<<"  ";cout<<endl;
         FOR(i,po.size())cout<<cnt[i]<<"  ";
         cout<<endl;
         /*
         ans=0;
         t1=0;
         while (ans<n && t1<po.size()){
             if(po[t1]==0 && ans<n)ans=n;
             else{
             if(cnt[t1]%2)cnt[t1]++;
             ans+=(pow(3,po[t1]))*cnt[t1];
             t1++;}
         }
         if(ans<n)ans=n;
         cout<<ii<<"--->"<<ans<<endl;*/
                
	 }  
    return 0;
}
