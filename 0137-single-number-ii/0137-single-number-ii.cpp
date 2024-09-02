class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitPosition(32, 0);


        for(int num : nums){
            for(int i=0; i< 32; i++){
                bitPosition[i] += ((num >> i) & 1);
            }
        }

        long long  ans  =0;
        for(int i = 0; i< 32; i++) {
            if(bitPosition[i] % 3){
                if(i == 31) {
                    ans -= (1 << i);
                } else {
                    ans |= (1 << i);
                }
            }
        }
        return (ans);
    }
};