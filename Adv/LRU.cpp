#include <list>

list<int>LRU;
map<int,int>key_val;
map<int,list<int>::iterator>f;
int capa,count1=0;

LRUCache::LRUCache(int capacity) {
    LRU.clear();
    key_val.clear();
    count1=0;f.clear();
    capa=capacity;
}

int LRUCache::get(int key) {
    cout<<"GET->";
    if(key_val.find(key)==key_val.end())return -1;
    LRU.erase(f[key]);
    LRU.push_back(key);
    list<int>::iterator it=prev(LRU.end());
    f[key]=it;
    return key_val[key];
}

void LRUCache::set(int key, int value) {
    cout<<"SET->";
    if(count1<capa){
        if(f.find(key)==f.end())
        {
            count1++;
            LRU.push_back(key);
            key_val[key]=value;
            f[key]=prev(LRU.end());
        }
        else
        {
            LRU.erase(f[key]);
            LRU.push_back(key);
            f[key]=prev(LRU.end());
            key_val[key]=value;
        }
    }
    else
    {
        int K=LRU.front();
        LRU.pop_front();
        f.erase(K);
        key_val.erase(K);
        LRU.push_back(key);
        f[key]=prev(LRU.end());
        key_val[key]=value;
    }
    for(auto v:LRU)cout<<v<<" ";
    cout<<"SET OUT->";
}
