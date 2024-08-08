class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) {
        int i = rStart, j = cStart;
        int diri = 0, dirj = 1;
        int twice = 2;
        vector<vector<int>> res;
        int move = 1;
        int next_move = 2;

        while(res.size() < (rows * cols)){
            if( i >= 0 && i < rows && j>=0 && j < cols){
                res.push_back({i, j});
            }
            i += diri;
            j += dirj;

            move -= 1;
            if(move == 0){
                int temp = diri;
                diri = dirj;
                dirj = -temp;
                twice -= 1;
                if(twice == 0){
                    twice = 2;
                    move = next_move;
                    next_move +=1;
                }
                else{
                    move = next_move-1;
                }
            }
        }
        return res;
    }
};