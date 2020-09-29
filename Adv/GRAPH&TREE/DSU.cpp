#include<bits/stdc++.h>
using namespace std;

//Approach A
void init(int arr[],int n){
    for(int i=0;i<n;i++) arr[i]=i;
}

bool find(int arr[],int a,int b){
    return (arr[a]==arr[b]);
}
void union(int arr[],int n,int a,int b){
    int temp=arr[a];
    for(int i=0;i<n;i++){
        if(arr[i]==temp) arr[i]=arr[b];
    }
}
//Approach B
int root(int arr[],int n,int a){
    while(arr[a]!=a)a=arr[a];
    return a;
}
bool find(int a,int b,int arr[],int n){
    return root(arr,n,a)==root(arr,n,b);
}
void union(int arr[],int n,int a,int b){
    int A=root(arr,n,a);
    int B=root(arr,n,b);
    arr[A]=B;
}
//APPROACH C  -FIND O(logN)
void initialize( int Arr[ ], int N)
{
    for(int i = 0;i<N;i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}
void weighted-union(int Arr[],int size[],int A,int B,int n)
{
    int root_A = root(Arr,n,A);
    int root_B = root(Arr,n,B);
    if(size[root_A] < size[root_B])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
    Arr[ root_B ] = Arr[root_A];
    size[root_A] += size[root_B];
    }
}
//Union with path compression
int root_x (int Arr[ ] ,int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ; 
        i = Arr[ i ]; 
    }
    return i;
}

//optimum O(logN)

int32_t main(){

}
