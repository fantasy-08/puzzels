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
double dist(lli x1,lli x2,lli y1,lli y2 )
{
    if(x1==x2 and y1==y2) return 0;
    if(x1==x2)return abs(y1-y2);
    if(y1==y2)return abs(x1-x2);
    return sqrt(pow((x2-x1),2)+pow((y2-y1),2));
}

int main() {
	 test{
	    lli x,y,a,b,c,x1,x2,x3,y1,y2,y3;cin>>x>>y;
	    cin>>a>>b>>c;
	    lli arr1[2*a],arr2[2*b],arr3[2*c];
	    double min=INT_MAX,d1,d2;
	    FOR(i,2*a)cin>>arr1[i];
	    FOR(i,2*b)cin>>arr2[i];
	    FOR(i,2*c)cin>>arr3[i];
        for(lli i=0;i<2*a;i+=2){
            x1=arr1[i];y1=arr1[i+1];
            d1=dist(x,x1,y,y1);
            //d2=dist(x,x2,y,y2);
            if(d1>min) continue;
            for(lli j=0;j<2*b;j+=2){
                x2=arr2[j];y2=arr2[j+1];
                d2=d1+dist(x2,x1,y2,y1);
                //d2=dist(x,x2,y,y2)+dist(x2,x1,y2,y1);
                if(d2>min)continue;
                for(lli k=0;k<2*c;k+=2){
                    
                    x3=arr3[k];y3=arr3[k+1];
                    d2+=dist(x2,x3,y2,y3);
                    //d2=dist(x1,x3,y1,y3);
                    //d1=min(d1);
                    if(min>d2 || min==-1)
                    min=d2;
                }
            }
        }
        /*for(lli i=0;i<2*a;i+=2){
            x1=arr1[i];y1=arr1[i+1];
            d1=dist(x,x1,y,y1);
            //d2=dist(x,x2,y,y2);
            if(d1>min) continue;
            for(lli j=0;j<2*b;j+=2){
                x2=arr2[j];y2=arr2[j+1];
                d1+=dist(x2,x1,y2,y1);
                //d2=dist(x,x2,y,y2)+dist(x2,x1,y2,y1);
                if(d1>min)continue;
                for(lli k=0;k<2*c;k+=2){
                    
                    x3=arr3[k];y3=arr3[k+1];
                    d1+=dist(x2,x3,y2,y3);
                    //d2=dist(x1,x3,y1,y3);
                    //d1=min(d1);
                    if(min>d1 || min==-1)
                    min=d1;
                }
            }
        }*/
        printf("%.14f\n",min);
        
	 }
	 
    return 0;
}

