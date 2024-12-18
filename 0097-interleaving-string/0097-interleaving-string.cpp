class Solution {
    bool solve(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp){
        if(i == s1.length() && j == s2.length())
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i < s1.length() && s1[i] == s3[i+j] && solve(s1,s2, s3, i+1, j,dp))
            return true;
        else if(j < s2.length() && s2[j] == s3[i+j] && solve(s1,s2, s3, i, j+1, dp))
            return true;
        dp[i][j] = false;
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1, -1));
        return solve(s1, s2, s3, 0,0, dp);
    }
};