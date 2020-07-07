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
lli dist(lli x1,lli x2,lli y1,lli y2 )
{
    return pow((x2-x1),2)+pow((y2-y1),2);
}
   
int main() {
	 test{
	    lli x,y,a,b,c;cin>>x>>y;
	    cin>>a>>b>>c;
	    lli arr1[2*a],arr2[2*b],arr3[2*c];
	    FOR(i,2*a)cin>>arr1[i];
	    FOR(i,2*b)cin>>arr2[i];
	    FOR(i,2*c)cin>>arr3[i];
        lli min1=INT_MAX,min2=INT_MAX,min12=INT_MAX,min22=INT_MAX,ind1,ind2,temp;
        long double ans1,ans2;
        for(lli i=0;i<2*a;i+=2){
            temp=dist(arr1[i],x,arr1[i+1],y);
            if(temp<min1)
                {min1=temp;ind1=i;}
        }//1 1
        
        
        for(lli i=0;i<2*b;i+=2){
            temp=dist(arr2[i],arr1[ind1],arr2[i+1],arr1[ind1+1]);
            if(temp<min12)
                {min12=temp;ind1=i;}
        }//1 2 
        ans1=sqrt(min1)+sqrt(min12);
        min12=INT_MAX;
        for(lli i=0;i<2*c;i+=2){
            temp=dist(arr3[i],arr2[ind1],arr3[i+1],arr2[ind1+1]);
            if(temp<min12)
                {min12=temp;ind2=i;}
        }// 1 3
        //cout<<arr3[ind2]<<" "<<arr3[ind2+1]<<endl;
        ans1+=sqrt(min12);
        //cout<<ans1;
        //ans 1 got 
        for(lli i=0;i<2*b;i+=2){
            temp=dist(arr2[i],x,arr2[i+1],y);
            if(temp<min2)
                {min2=temp;ind2=i;}
        }
        //cout<<min2;
        min22=INT_MAX;
	    for(lli i=0;i<2*a;i+=2){
            temp=dist(arr1[i],arr2[ind2],arr1[i+1],arr2[ind2+1]);
            if(temp<min22)
                {min22=temp;ind1=i;}
        }
        //cout<<min22;
        ans2=sqrt(min2)+sqrt(min22);
        min12=INT_MAX;
        for(lli i=0;i<2*c;i+=2){
            temp=dist(arr3[i],arr1[ind1],arr3[i+1],arr1[ind1+1]);
            if(temp<min12)
                {min12=temp;ind2=i;}
        }
        //cout<<min12;
        ans2+=sqrt(min12);
        //cout<<ans2;
        //ans 2 got
        
        if(ans1>ans2)cout<<ans2<<endl;
        else cout<<ans1<<endl;
	 }
	 
    return 0;
}
