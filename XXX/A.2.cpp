#include<bits/stdc++.h>
#define in long long int
using namespace std;
int main(){
    in n,temp,y;
    cin>>n;
    while(n--){
        cin>>temp;
        //cout<<temp;
        y=temp/14;
        y=y*14;//cout<<y;
        if(y==temp || temp<=14)cout<<"NO\n";
        else{
        temp=temp-y;
        //cout<<temp;
        if(temp>0&&temp<7)cout<<"YES\n";
        else cout<<"NO\n";
        }
        
    }
    return 0;
}
/*if(temp<=28)cout<<"NO\n";
            else{
            temp-=28;
            if(temp>0 && temp<=6)cout<<"YES\n";
            else cout<<"NO\n";
        }*/