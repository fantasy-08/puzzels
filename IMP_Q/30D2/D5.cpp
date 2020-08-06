struct Trie
{
    struct Trie * children[256];
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
        int i=word[j];
        if(dict->children[i]==nullptr){
            dict->children[i]=new Trie();
        }
        dict=dict->children[i];
    }
    dict->isWord=true;
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
        Trie *temp=dict;
        for(int i=0;i<word.size();i++){
            if(temp->children[word[i]]==nullptr)return false;
            temp=temp->children[word[i]];
        }
        return temp->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */