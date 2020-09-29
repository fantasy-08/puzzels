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
#define L(x)	((x)<<1)
#define R(x)	(((x)<<1)+1)
#define MOD 1000000007
using namespace std;
struct TrieNode{
    struct TrieNode *children[26];
    bool isEndOfWord;
};
struct TrieNode *getNode(void){
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord=false;
    FOR(i,26) pNode->children[i]=NULL;
    return pNode;
}
void insert(struct TrieNode *root ,string key){
    struct TrieNode *pCrawl=root;
    FOR(i,key.size()){
        int index=key[i]-97;
        if(!pCrawl->children[index])
            pCrawl->children[index]=getNode();
        pCrawl=pCrawl->children[index];
    }
    pCrawl->isEndOfWord=true;
}
bool search(struct TrieNode *root,string key){
    struct TrieNode *pCrawl =root;
    FOR(i,key.size()){
        if(!pCrawl->children[key[i]-'a']) return false;
        pCrawl=pCrawl->children[key[i]-'a'];
    }
    return (pCrawl!=NULL && pCrawl->isEndOfWord);
}
int main() {
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode(); 

    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 

    search(root, "the")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "these")? cout << "Yes\n" : 
                           cout << "No\n"; 
    return 0;
}
