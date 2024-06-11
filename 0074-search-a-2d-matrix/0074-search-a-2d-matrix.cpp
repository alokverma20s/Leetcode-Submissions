class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n= matrix.size()-1;
        int m = matrix[0].size()-1;

        while(n >= 0 && m >= 0){
            if(matrix[n][m] > target){
                if(n-1 >= 0 && matrix[n-1][m] >= target){
                    n--;
                }
                else if(m-1 >= 0 && matrix[n][m-1] >= target){
                    m--;
                }
                else{
                    return false;
                }
            }else if(matrix[n][m] == target)
                return true;
            else 
                return false;
        }
        return false;
    }
};