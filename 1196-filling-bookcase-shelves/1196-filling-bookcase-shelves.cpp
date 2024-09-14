class Solution {
    int solve(int i, vector<vector<int>>& books, int &d, int height, int remWidth, vector<vector<int>> &dp){
        if(i == books.size()) return height;
        if(dp[i][remWidth] != -1) return dp[i][remWidth];

        int notTake = solve(i+1, books, d, books[i][1], d-books[i][0], dp) + height;
        int take = INT_MAX;
        if(remWidth-books[i][0] >=0){
            take = solve(i+1, books, d, max(height, books[i][1]), remWidth-books[i][0], dp);
        }
        return dp[i][remWidth] = min(take, notTake);
    }
public:
    int minHeightShelves(vector<vector<int>>& books, int d) {
        vector<vector<int>> dp(books.size()+1, vector<int>(d+1, -1));
        return solve(0, books, d, 0, d,dp);
    }
};