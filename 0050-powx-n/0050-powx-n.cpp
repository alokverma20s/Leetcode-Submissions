class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if(n < 0) nn = -1 *nn;
        double ans = 1.0;
        while(nn){
            if(nn & 1){
                ans = ans * x;
                nn--;
            }
            else{
                x = x * x;
                nn = nn >> 1;
            }
        }

        if( n< 0) return (1.0 / ans);
        return ans;
    }
};