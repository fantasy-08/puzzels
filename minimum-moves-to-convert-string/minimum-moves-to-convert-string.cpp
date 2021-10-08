class Solution {
public:
    int minimumMoves(string s) {
        int i=0,move=0;
        while(i<s.size()){
            if(s[i]=='X'){
                move++,i+=3;
            }else i++;
        }
        return move;
    }
};