vector<int>lps(const string A)
{
    int n=A.size();
    vector<int>l(n,0);
    int len=0,i=1;
    while(i<n)
    {
        if(A[i]==A[len])
        {
            len++;
            l[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=l[len-1];
            }
            else
            {
                l[i]=0;
                len=0;
                i++;
            }
        }
    }
    return l;
}
return KMP(const string A, const string B) {
    int n=A.size(),m=B.size();
    if(n==0 || m==0)return -1;
    vector<int>LPS=lps(B);
    int i=0,j=0;
    while(i<n)
    {
        if(A[i]==B[j])
        {
            i++,j++;
        }
        if(j==m)return i-j;
        else if(i<n && A[i]!=B[j])
        {
            if(j!=0) j = LPS[j-1];
            else i++;
        }
    }
    return -1;
}