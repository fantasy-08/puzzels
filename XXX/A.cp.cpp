#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define clr(x) memset(x,0,sizeof(x))
#define fr(k,i,n) for(i=k;i<n;i++)
#define vi vector<int>
#define vl vector<long>
#define pb push_back
#define tt int T;T=1;while(T--)
#define mi unordered map<int ,int >
#define ft first
#define sd second
int main() {
    tt{
        ll i,j,n,m;
        cin>>n;
        ll sum,x,l;
        ll b=0,d;
        char c[121];
        fr(0,i,n){
        	b=0;
        	d=0;
        	sum=0;
        	scanf("%s",c);
        	l= strlen(c);
        	fr(0,j,l){
        		x=c[j]-'0';
        		if(x%2==0)b++;
        		if(x==0)d=1;
        		sum+=x;
			}
			if(b>1&&d==1&&sum%3==0){
				cout<<"red\n";
			}else
				cout<<"cyan\n";
		}
	return 0;
}
}