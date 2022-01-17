class Solution {
public:
    int go(int x, vector<int>& arr){
        int l = 0, h = arr.size()-1, ans = arr.size()-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(arr[mid]==x)
                return mid;
            if(arr[mid]>x){
                ans = mid;
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int index = go(x, arr);
        deque<int>q;
        int low = index, high = index;
        
        if(arr[low] == x) {
            q.push_back(x);
            low--, high++, k--;
        } else {
            low--;
        }
        while(k--){
            int abs1 = low>=0 ? abs(x-arr[low]) : INT_MAX;
            int abs2 = high>=arr.size() ? INT_MAX : abs(x-arr[high]);
            
            if(abs1>abs2){
                q.push_back(arr[high++]);
            } else {
                q.push_front(arr[low--]);
            }
        }
        
        vector<int>ans (q.begin(), q.end());
        return ans;
    }
};
