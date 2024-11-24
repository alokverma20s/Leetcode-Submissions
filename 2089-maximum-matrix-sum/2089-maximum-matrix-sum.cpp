class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long mini = INT_MAX;
        long long sum = 0;
        long long cnt= 0;
        for(long long i=0; i< matrix.size(); i++){
            for(long long j=0; j< matrix[0].size(); j++){
                sum += (long long)abs(matrix[i][j]);
                if(matrix[i][j] < 0){
                    cnt++;
                }
                mini  = min(mini, (long long)abs(matrix[i][j]));
            }
        }
        // cout<< mini<<" "<<cnt<<" "<<sum;
        if((cnt&1 == 1) && (mini != INT_MAX)){
            sum -= ((long long)2*mini);
        }
        return sum;
    }
};