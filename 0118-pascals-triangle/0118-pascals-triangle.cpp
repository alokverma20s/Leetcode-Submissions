class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for(int i=1; i<=numRows; i++){
            vector<int>temp(i, 1);
            ans[i-1]=temp;
        }
        for(int i=2; i< numRows; i++){
            for(int j = 1; j< i; j++){
                // cout<<i<<" "<<j<<endl;
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
        }
        return ans;
    }
};