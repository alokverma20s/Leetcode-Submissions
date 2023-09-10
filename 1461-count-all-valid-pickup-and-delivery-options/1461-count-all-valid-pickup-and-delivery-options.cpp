class Solution {
    int MOD = 1000000007;
public:
    int countOrders(int n) {
        int slots = 2 * n;
        long long ans =1;

        while(slots > 0){
            long long valid = ((slots * (slots-1))/2)%MOD;
            ans = (ans * valid) % MOD;
            slots -=2;
        }
        return ans;
    }
};