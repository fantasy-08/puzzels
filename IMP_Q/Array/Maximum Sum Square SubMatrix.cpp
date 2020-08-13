int Solution::solve(vector<vector<int> > &A, int B) {
    int n=A.size();
    int sum[n+1][n+1];
    memset(sum,0,sizeof(sum));
    for(int i=0;i<n;i++)
        sum[i+1][1]=A[i][0]+sum[i][1],sum[1][i+1]=A[0][i]+sum[1][i];
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+A[i-1][j-1];
        }
    }
    int ans=INT_MIN;
    for(int i=1;i+B-1<=n;i++){
        for(int j=1;j+B-1<=n;j++){
            int temp=sum[i+B-1][j+B-1]+sum[i-1][j-1]-(sum[i-1][j+B-1]+sum[i+B-1][j-1]);
            ans=max(ans,temp);
        }
    }   
    /*for(int i=1;i+B-1<=n;i++){
        for(int j=1;j+B-1<=n;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return ans==INT_MIN?0:ans;
    
}
