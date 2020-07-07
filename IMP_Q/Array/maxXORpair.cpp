//#pragma GCC optimize "trapv"//  WA to RE int!!
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
#define all(zz) zz.begin(),zz.end()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define error(x) cerr << #x <<" is " << x << endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fint fast;test
#define set(a,x) memset(a,x,sizeof(a));
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
using namespace std;
class trieNode{
    trieNode *left;
    trieNode *right;
}
void insert(int n,trieNode *head){
    trieNode *curr=head;
    for(int i=31;i>=0;i--){
        int b=(n>>i)&1;
        if(b==0){
            if(curr->left) curr=curr->left;
            else{
                curr->left=new trieNode();
                curr=curr->left;
            }
        }
        else{
            if(!curr->right) curr->right=new trieNode();
            curr=curr->right;
        }
    }
}
int findMaxXorPair(trieNode *head,int *arr,int n){
    int max_ans=INT_MIN;
    for(int i=0;i<n;i++){
        trieNode *curr=head;
        int val=arr[i];
        int curr_xor=0;
        for(int j=31;j>=0;j--){
            int b=(val>>j)&1;
            if(b==0){
                if(curr->right){
                    curr_xor+=pow(2,j);
                    curr=curr->right;
                }
                else{
                    curr=curr->left;
                }
            }
            else{
                if(curr->left){
                    curr_xor+=pow(2,j);
                    curr=curr->left;
                }
                else{
                    curr=curr->right;
                }

            }
        }
        max_ans=max(max_ans,curr_xor);
    }
    return max_ans;
}
int main() {
       
    return 0;
}
