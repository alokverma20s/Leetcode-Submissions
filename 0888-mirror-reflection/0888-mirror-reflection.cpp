class Solution {
public:
    int mirrorReflection(int p, int q) {
        int i=1;
        while(true){
            if( i * q % p == 0){
                if(i%2){
                    if(((i*q)/p)%2) return 1;
                    else return 0;
                }
                else{
                    if(((i*q)/p)%2) return 2;
                }
            }
            i++;
        }
        return 3;
    }
};