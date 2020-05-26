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

struct Trie{
    struct Trie* children[26];
    bool isWord;
    Trie(){
         isWord=false;
        FOR(i,26) children[i]=NULL;
    }
}; 

void insert(Trie* root,string word){
    FOR(i,word.size()){
        if(root->children[word[i]-'a']){
            root=root->children[word[i]-'a'];
        }
        else{
            root->children[word[i]-'a']=new Trie();
            root=root->children[word[i]-'a'];
        }
    }
    root->isWord=true;
}

bool search(Trie* root,string s){
    FOR(i,s.size()){
        if(root->children[s[i]-'a']){
            root=root->children[s[i]-'a'];
        }
        else
        return false;
    }
    return root->isWord;
}

void solve(){
    Trie* trie_node=new Trie();
    int n;
    cin>>n;
    string temp;
    FOR(i,n){
        cin>>temp;
        cout<<(search(trie_node,temp)?"YES":"NO")<<endl;
        insert(trie_node,temp);
    }
}
  
int main() {
    fint{
            solve();	   
        }
 return 0;
}
