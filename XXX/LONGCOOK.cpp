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
lli year[1000000];
vlli hash1;
lli day(lli year)
{
  lli yr, a, lyrs, day;
  yr=year;
  a=yr-1;
  lyrs=a/4-a/100+a/400;
  day=(a+ lyrs)%7;
  return day;
  //2,3 wed and thursday
}
bool isleap(int year)  
{  
    return (((year % 4 == 0) && (year % 100 != 0)) || 
             (year % 400 == 0));  
} 
void make_hash1(){
    hash1.clear();
    lli temp;
    year[0]=0;
    for(lli i=1;i<=403;i++){
        if(i>1){
            if(isleap(i)){
                if(day(i)==2) {year[i]=year[i-1]+1;}
                else year[i]=year[i-1];
            }
            else{
                temp=day(i);
                if((temp==2)||(temp==3)) {year[i]=year[i-1]+1;}
                else year[i]=year[i-1];
            }
            hash1.pb(year[i]);
        }
    }
}
lli ans_give(lli n){
    if(n<=2) return 0;
    n-=2;
    lli final=0,temp;
    final=(n)/400;
    final*=101;
    final+=hash1[(n%400)];
    return final;
}
int main() {
    make_hash1();
    test{
        lli n,yr,n1,yr1,temp,ans=0;
        cin>>n>>yr>>n1>>yr1;
        if(yr!=yr1){
            ans=ans_give(yr1)-ans_give(yr-1);
            if(n>2){
                if(isleap(yr) && day(yr)==2) ans--;
                else if(!isleap(yr)){
                    temp=day(yr);
                    if(temp==2||temp==3) ans--;
                }
            }
            if(n1<2){
                if(isleap(yr1) && day(yr1)==2) ans--;
                else if(!isleap(yr1)){
                    temp=day(yr1);
                    if(temp==2||temp==3) ans--;
                }
            }
            cout<<ans<<endl;
        }
        else{
            if(n>2) cout<<0<<endl;
            else if(2>=n && n1>=2){
                temp=day(yr);
                if(isleap(yr)){
                    if(temp==2){
                         cout<<1<<endl;
                    }
                    else cout<<0<<endl;
                }
                else{
                    if(temp==2 || temp==3){
                         cout<<1<<endl;
                    }
                    else cout<<0<<endl;
                }
            }
            else cout<<0<<endl;
        }
    }
    return 0;
}

