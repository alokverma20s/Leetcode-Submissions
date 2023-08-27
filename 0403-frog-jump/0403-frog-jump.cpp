class Solution
{
    public:
        bool canCross(vector<int> &stones)
        {
            int n = stones.size();
            if (stones[1] != 1) 
                return false;
            if (n == 2) 
                return true;
            int jumps[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    jumps[i][j] = 0;
                    
            jumps[1][1] = 1;
            for (int i = 2; i < n; i++){
                for (int j = 1; j < i; j++){
                    int d = stones[i] - stones[j];
                    if (d - 1 < n && jumps[j][d - 1])
                        jumps[i][d] = 1;
                    else if (d < n && jumps[j][d])
                        jumps[i][d] = 1;
                    else if (d + 1 < n && jumps[j][d + 1])
                        jumps[i][d] = 1;
                    if (i == n - 1 && d < n && jumps[i][d])
                        return true;
                }
            }
            return false;
        }
};