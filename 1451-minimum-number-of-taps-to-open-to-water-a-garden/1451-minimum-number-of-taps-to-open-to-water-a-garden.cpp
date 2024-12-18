class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n+1, n+5);
        dp[0] = 0;
        for(int i = 0; i <= n; i++){
            int leftReach = max(0, i-ranges[i]);
            for(int j = max(0, i-ranges[i]+1); j <= min(i+ranges[i], n); j++){
                dp[j] = min(dp[j], dp[leftReach]+1);
            }
        }
        return dp[n] == n+5 ? -1 : dp[n];
    }
};