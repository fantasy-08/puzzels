class Solution {
public:
    int pivot(vector<int>& A){
        int l=0,h=A.size()-1;
        int n=A.size();
        while(l<=h){
            int mid=l+(h-l)/2;
            if(A[(mid-1+n)%n]<A[mid%n] && A[mid%n]>A[(mid+1)%n])return mid;
            if(A[l]<=A[mid])l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
    int bsearch(vector<int>& A, int target,int l,int h){
        while(l<=h){
            int mid=l+(h-l)/2;
            if(A[mid]==target)return mid;
            if(A[mid]>target)h=mid-1;
            else l=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int lar= pivot(nums);
        int ind=bsearch(nums,target,0,lar);
        if(ind!=-1)return ind;
        ind=bsearch(nums,target,lar+1,nums.size()-1);
        return ind;
    }
};
