class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_set<int> row, col;
        for(int i=0; i<n ; i++){
            for(int j=0; j< m ;j++){
                if(mat[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto st: row)
            for(int i=0; i<m; i++)
                mat[st][i] = 0;
        for(auto st: col)
            for(int i=0; i<n; i++)
                mat[i][st] = 0;
    }
};