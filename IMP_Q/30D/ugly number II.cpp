class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long int>q;
        q.insert(1);
        long long int mini;
        while(n--){
            mini=*q.begin();
            q.erase(q.begin());
            q.insert(mini*2);
            q.insert(mini*3);
            q.insert(mini*5);
        }
        return mini;
    }
};