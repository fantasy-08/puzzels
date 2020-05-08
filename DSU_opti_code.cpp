//#pragma GCC optimize "trapv"//  WA to RE int!!
#include <bits/stdc++.h>
using namespace std;

int find(int par[],int n,int a){
    if(par[a]<0){
        return a;
    }
    return par[a]=find(par,n,par[a]);
}
void uni(int par[],int n,int a ,int b){
    int root_a=find(par,n,a);
    int root_b=find(par,n,b);
    if(abs(par[root_a])>abs(par[root_b])){
        par[root_a]+=par[root_b];
        par[root_b]=root_a;
    }
    else{
        par[root_b]+=par[root_a];
        par[root_a]=root_b;
    }
}


int32_t main() {
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        arr[i]=-1;
    }   
    while(m--){
        int a,b;
        cin>>a>>b;
        uni(arr,n,a,b);
        map<int,int>x;
        for(int i=1;i<=n;i++){
            if(arr[i]<0){
                x[-arr[i]]+=1;
            }
        }
        for(auto v:x){
            for(int i=0;i<v.second;i++)
                cout<<v.first<<" ";
        }
        cout<<endl;
    }
    return 0;
}
