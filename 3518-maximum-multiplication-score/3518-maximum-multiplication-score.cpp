class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<long long> memo(4, LLONG_MIN);
        long long n = b.size();

        for (long long i = 0; i < n; ++i) {
            for (long long j = min(i, 3ll); j >= 0; --j)
                (j == 0) ? 
                    memo[j] = max(memo[j], (long long)(a[j] * (long long)b[i])): 
                    memo[j] = max(memo[j], memo[j - 1] + (long long)(a[j] * (long long)b[i]));
        }
        return memo[3];
    }
};