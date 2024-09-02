class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;

        while(n > 0){
            if(n & 1){
                n= n >> 1;
                break;
            } 
            n = n >> 1;
        }
        if( n == 0) return 1;
        return 0;
    }
};