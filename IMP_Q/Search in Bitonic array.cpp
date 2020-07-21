int index(vector<int>& A,int B)
{
    int l=0,h=A.size()-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(A[mid-1]<A[mid] && A[mid]>A[mid+1])return mid;
        if(A[mid]<A[mid+1])l=mid+1;
        else h=mid-1;
    }
    return A.size()-1;
}
int inc(vector<int>& A,int B,int l,int h)
{
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(A[mid]==B)return mid;
        if(A[mid]<B)l=mid+1;
        else h=mid-1;
    }
    return -1;
}
int dec(vector<int>& A,int B,int l,int h)
{
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(A[mid]==B)return mid;
        if(A[mid]>B)l=mid+1;
        else h=mid-1;
    }
    return -1;
}
int Solution::solve(vector<int> &A, int B) {
    int l=0,h=A.size();
    int middle=index(A,B);
    int I=inc(A,B,0,middle);
    int H=dec(A,B,middle+1,A.size()-1);
    if(I!=-1)return I;
    if(H!=-1)return H;
    return -1;
}
