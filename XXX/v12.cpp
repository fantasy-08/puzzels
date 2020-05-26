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
int whose(string s){

    lli vv=0,cc=0;
    /*FOR (i,s.size()-1){
        if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') continue;
        if(s[i+1]=='a' || s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u') continue;
        else return 0;
        }
    FOR(i,s.size()){
        if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') vv++;
        else cc++;
    }*/
    FOR(i,s.size()-1){
    	vv=0,cc=0;
    	for(lli j=i;j<s.size();j++){
    		if( s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') vv++;
        	else cc++;
		}
		if(vv<cc)return 0;
	}
	return 1;
    /*if(vv>=cc)
    return 1;
    else
    return 0;*/
	}
   
int main() {
	test{
		lli n,k_bob=0,k_kal=0,hash_b[26]={0},hash_k[26]={0},count=0;
		double ans_b=1.0,ans_k=1.0,ans;
		vector<string>bob,kal;
		string bobs="",kals="",temp,uni_b="",uni_k="";
		cin>>n;
		FOR(i,n){
			cin>>temp;
			if(whose(temp)==1){
				bob.pb(temp);
				bobs+=temp;
				k_bob++;
			}
			else{
				kal.pb(temp);
				kals+=temp;
				k_kal++;
			}
			
		}
		cout<<"ALICE: "<<bobs<<" BOB: "<<kals<<endl;
		FOR(i,bobs.size()){
			if(hash_b[bobs[i]-97]==0)uni_b+=bobs[i];
			hash_b[bobs[i]-97]++;
		}
		FOR(i,kals.size()){
			if(hash_k[kals[i]-97]==0)uni_k+=kals[i];
			hash_k[kals[i]-97]++;
		}
		FOR(i,uni_b.size()){
			count=0;
			FOR(j,k_bob){
				FOR(k,bob[j].size())
					if(uni_b[i]==bob[j][k])
						{count++;break;}
						}
		ans_b*=((count)/(pow((hash_b[uni_b[i]-97]),k_bob)));
		}
		FOR(i,uni_k.size()){
			count=0;
			FOR(j,k_kal){
				FOR(k,kal[j].size())
					if(uni_k[i]==kal[j][k])
						{count++;break;}
						}
		ans_k*=((count)/(pow((hash_k[uni_k[i]-97]),k_kal)));
		}
		ans=(ans_b)/(ans_k);
    	if((10000010-ans)<=20||ans<0)printf("Infinity\n");
    	else {printf("%.14f\n",ans);}
		
	}   
    return 0;
}

