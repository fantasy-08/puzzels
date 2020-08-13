
struct Matrix
{
	int a[2][2]={{0,0},{0,0}};
	Matrix operator *(const Matrix& other)
	{
		Matrix res;
		FOR(i,2)FOR(j,2)FOR(k,2)
		res.a[i][j]=(res.a[i][j]%MOD+(a[i][k]%MOD)*(other.a[k][j]%MOD))%MOD;
		return res;			
	}
};
Matrix power(Matrix A,int n)
{
	Matrix res;
	FOR(i,2)res.a[i][i]=1;
	while(n>0)
	{
		if(n&1)res=res*A;
		n/=2;
		A=A*A;
	}
	return res;
}
