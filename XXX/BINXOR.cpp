#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#define FOR(i,n) for(long long int i=0;i<n;i++)
#define FORR(i,n) for(long long int i=n;i>=0;i--)
#define pb push_back
#define vlli vector<long long int>
#define slli set<long long int>
#define mlli map<long long int,long long int>
#define lli long long int 
#define test lli tt1234; cin>>tt1234;while(tt1234--)
#define MOD 1000000007
using namespace std;
vector<string>a,b;
lli dec(string n) 
{ 
    string num = n; 
    lli dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    lli base = 1; 
  
    lli len = num.length(); 
    for (lli i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 
void permute(string aa,string bb) 
{ 
    sort(aa.begin(), aa.end()); 
    do { 
       a.push_back(aa); 
    } while (next_permutation(aa.begin(), aa.end())); 
    sort(bb.begin(), bb.end()); 
    do { 
       b.push_back(bb); 
    } while (next_permutation(bb.begin(), bb.end())); 
}   
   
int main() {
	   test{
	       lli n,a12,b12;
	       cin>>n;
	       string str1,str2;
	       set<lli>cc;
	       cin>>str1>>str2;
	       a.clear();
	       b.clear();
	       permute(str1,str2);
	  // FOR(i,b.size())cout<<b[i]<<endl;
	       FOR(i,a.size()){
	           FOR(j,b.size()){
	               a12=dec(a[i]);
	               b12=dec(b[j]);
	              //cout<<(a12^b12)<<endl;
	               cc.insert(a12^b12);
	           }
	       }
	       
		   cout<<endl;
	       cout<<cc.size()<<endl;
	   }
    return 0;
}

