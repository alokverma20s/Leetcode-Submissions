class Solution {
public:
    long long maxEnergyBoost(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<long long> prefixa(n, 0), prefixb(n, 0);

        prefixa[0] = a[0];
        prefixb[0] = b[0];
        prefixa[1] = prefixa[0] + a[1];
        prefixb[1] = prefixb[0] + b[1];

        for (int i = 2; i < n; i++) {
            prefixa[i] = max(prefixa[i - 1] + a[i], prefixb[i - 2] + a[i]);
            prefixb[i] = max(prefixb[i - 1] + b[i], prefixa[i - 2] + b[i]);
        }
        return max(prefixa[n-1], prefixb[n-1]);
    }
};