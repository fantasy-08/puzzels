void multiply(vector<vector<int>>&A,vector<vector<int>>B){
	int n=A.size(),m=B.size();
	
	vector<vector<int>>mul(n,vector<int>(n,0));
	for (int i = 0; i < 3; i++) 
    { 
        for (int j = 0; j < 3; j++) 
        { 
            mul[i][j] = 0; 
            for (int k = 0; k < 3; k++) 
                mul[i][j] += A[i][k]*B[k][j]; 
        } 
    } 
    for (int i=0; i<3; i++) 
        for (int j=0; j<3; j++) 
            A[i][j] = mul[i][j];  
}
