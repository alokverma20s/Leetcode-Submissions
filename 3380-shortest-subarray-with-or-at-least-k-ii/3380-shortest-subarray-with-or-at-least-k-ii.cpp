class Solution{
    void addContribution(int n, vector<int> &bitArray, bool add){
        bitset<32> t(n);

        for (int i = 0; i < 32; i++){
            if (add)bitArray[i] += t[i];
            else bitArray[i] -= t[i];
        }
    }
    int calculateValue(vector<int> &bitArray){
        int ans =0;
        for(int i=0; i< 32; i++){
            ans += ((bitArray[i] == 0 ? 0 : 1) * (1 << i));
        }
        return ans;
    }
    public:
        int minimumSubarrayLength(vector<int> &nums, int k){
            int n = nums.size();
            int i = 0, j = 0;
            int ans = INT_MAX;
            vector<int> bitArray(32, 0);

            while (j < n) {
                addContribution(nums[j], bitArray, true);
                while(calculateValue(bitArray) >= k && i <= j){
                    ans = min(ans, j-i+1);
                    addContribution(nums[i], bitArray, false);
                    i++;
                }
                j++;
            }
            return ans == INT_MAX ? -1: ans;
        }
};