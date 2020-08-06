struct Trie
{
    struct Trie * children[26];
    bool isWord;
    Trie()
    {
        for(int i=0;i<26;i++)children[i]=nullptr;
        isWord=false;
    }
};
void insert(Trie *dict,string word)
{
    for(int j=0;j<word.size();j++){
        int i=word[j]-'a';
        if(dict->children[i]==nullptr){
            dict->children[i]=new Trie();
        }
        dict=dict->children[i];
    }
    dict->isWord=true;
}
bool searchW(Trie * dict,string word,int i)
{
    if(i==word.size()-1)
    {
        if(word[i]!='.'){
            dict=dict->children[word[i]-'a'];
            if(dict && dict->isWord)return true;
            return false;
        }
        for(int i=0;i<26;i++){
            if(dict->children[i] && dict->children[i]->isWord)return true;
        }
        return false;
    }
    if(word[i]!='.'){
        if(dict->children[word[i]-'a']==NULL)return false;
        return searchW(dict->children[word[i]-'a'],word,i+1);
    }
    bool flag=false;
    for(int j=0;j<26;j++){
        if(dict->children[j])
        flag|=searchW(dict->children[j],word,i+1);
    }
    return flag;
}
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie *dict;
    WordDictionary() {
        dict=new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        insert(dict,word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchW(dict,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */