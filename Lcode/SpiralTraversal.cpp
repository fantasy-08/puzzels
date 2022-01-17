class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
        int n=A.size(), m=A[0].size();
        vector<int> ans;
        int a = 0, b = m-1, c = 0, d = n-1, step = 0;
        while (a<=b && c<=d) {
            if (step == 0) {
                for(int i=a; i<=b; i++){
                    ans.push_back(A[c][i]); 
                }
                c++;
            } else if(step == 1) {
                for(int j=c; j<=d; j++) {
                    ans.push_back(A[j][b]);
                }
                b--;
            } else if(step == 2) {
                for(int i=b;i>=a;i--){
                    ans.push_back(A[d][i]);
                }
                d--;
            } else {
                for(int j=d;j>=c;j--){
                    ans.push_back(A[j][a]);
                }
                a++;
            }
            step = (step + 1)%4;
        }
        
        return ans;
    }
};
