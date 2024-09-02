class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long totalXor = 0;
        for(int i : nums) totalXor ^= i;

        cout<<totalXor<< " ";
        long long mask = totalXor & (-totalXor);
        cout<< mask;
        int num1 = 0, num2 = 0;
        for(int i: nums){
            if(mask & i) num1 ^= i;
            else num2 ^=  i;
        }
        
        return {num1, num2};
    }
};