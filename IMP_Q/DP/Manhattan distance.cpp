vector<vector<int> > Solution::solve(int A, vector<vector<int> > &B) {
    int n = B.size();
    int m = B[0].size();
    if(n==0 && m==0) return B;
    
    vector<vector<int>> temp = B;
    
    for(int i = 1; i<=A; i++){
        for(int j = 0; j <= n-1; j++){
            for(int k = 0; k<= m-1; k++){
                //compare with the previous array and build a new one
                if(k>0){ B[j][k] = max(B[j][k], temp[j][k-1]); } //if not in leftmost column, consider value on left
                if(j>0){ B[j][k] = max(B[j][k], temp[j-1][k]); } //if not in topmost row, consider value above it
                if(k<m-1){ B[j][k] = max(B[j][k], temp[j][k+1]); } //if not in rightmost column, consider value on right
                if(j<n-1){ B[j][k] = max(B[j][k], temp[j+1][k]); } //if not in bottommost row, consider value below it
            }
        }
        temp = B; //copy newly changed array to temp, to use it as base for current length+1
    }
    return B;
}
