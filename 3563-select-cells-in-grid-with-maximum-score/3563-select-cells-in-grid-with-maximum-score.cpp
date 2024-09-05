class Solution {
    int solve(int i, int n, vector<int> &v, map<int, vector<int>> &mp, int mask, vector<vector<int>> &dp){
        if(i == n) return 0;
        
        if(dp[mask][i] != -1) return dp[mask][i];
        int ans = 0;

        for(auto j: mp[v[i]]){
            if((mask & (1 << j)) == 0){
                ans = max(ans, v[i] + solve(i+1, n, v, mp, (mask | (1 << j)), dp));
            }
        }
        return dp[mask][i] = max(ans, solve(i+1, n, v, mp, mask, dp));
    }
public:
    int maxScore(vector<vector<int>>& grid) {
        unordered_set<int> st;
        int n = grid.size(), m = grid[0].size();
        for(auto i: grid)
            for(auto j: i) st.insert(j);
        

        vector<int> v;
        for(auto i: st) v.push_back(i);

        sort(v.rbegin(), v.rend());
        map<int, vector<int>> mp;

        for(int i=0; i< n; i++)
            for(int j=0; j< m; j++)
                mp[grid[i][j]].push_back(i);
        vector<vector<int>> dp(1025, vector<int>(101, -1));
        return solve(0, v.size(), v, mp, 0, dp);
            
    }
};