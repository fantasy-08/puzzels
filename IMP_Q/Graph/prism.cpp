class Solution {
public:
    bool isPowerOfFour(int num) {
        int ind=-1;
        for(int i=0;i<32;i++){
            if((num>>i)&1 && ind!=-1)return false;
            else if((num>>i)&1)ind=i;
        }
        return ind%2==0;
    }
};