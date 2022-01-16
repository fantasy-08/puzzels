## Recursive to Iterative solution

* Create a `dp` array with same dimensions as used in recusive approach.
* The loop will be reverse of want the recusive solution had
  * if we have `go(0)` which goes to pos
  * then, iteration will be from `pos` to `0`
  * `for(int i=pos;i>=0;i--)`
* Base cases of recursive solution is handled before the loop starts.
* Instead of calling function again (recusion) use the address of the `dp` array.
* Return the `dp` array value with dimensions value that are passed to recusive function call (at the beginning / first call).

#### Bottom-Up approach

```cpp
class Solution {
public:
    long long dp[100001];
    
    long long go(int pos, vector<vector<int>>& a){
        if(pos>=a.size())
            return 0;
        if(dp[pos]!=-1)
            return dp[pos];
        return dp[pos]=max(a[pos][0] + go(pos+a[pos][1]+1, a), go(pos+1, a));
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, -1, sizeof(dp));
        return go(0, questions);
    }
};
```

#### Top-Down approach

```cpp
class Solution {
public:
    long long dp[100001];
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp, 0, sizeof(dp));
        int n = questions.size();
        dp[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
          if(pos+a[i][1]+1 < pos.size())
            dp[i] = max(a[i][0] + dp[pos+a[i][1]+1], dp[i+1]);
          else 
            dp[i] = dp[i+1];
        }

        return dp[0];
    }
};
```
