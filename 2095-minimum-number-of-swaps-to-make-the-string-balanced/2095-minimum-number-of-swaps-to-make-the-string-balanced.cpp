class Solution {
public:
    int minSwaps(string s) {
        int lb=0;
        int moves=0;
        for(int i=0; i<s.size(); i++)
            if(s[i]==']'){
                if(lb==0){
                    moves++;
                    lb++;
                }
                else lb--;
            }
            else lb++;
        return moves;
    }
};