bool go(int i,int j,int len,string A,string B)
{
	if(len==1)return A[i]==B[j];
	bool flag=false;
	for(int k=1;k<len;k++)
		flag|=go(i,j,k,A,B)&&go(i+k,j+k,len-k,A,B);
	for(int k=1;k<len;k++)
		flag|=go(i,j+len-k,k,A,B)&&go(i+len-k,j,len-k,A,B);
		return flag;
}