#include <iostream>

using namespace std;

int main() {
int n,i,ans=0;
cin>>n;
char c[n];
for(i=0;i<n;i++)
cin>>c[i];
for(i=0;i<n-1;i++){
    if(c[i]=='V'&&c[i+1]=='K'){
        ans++;
        char t=c[i];
        c[i]=c[i+1];
        c[i+1]=t;
        if(i<2)
        i=0;
        else
        i-=2;
    }
}
cout<<ans<<endl;
}