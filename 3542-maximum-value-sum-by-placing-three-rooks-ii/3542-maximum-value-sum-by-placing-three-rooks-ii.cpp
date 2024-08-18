class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int,int>>> cd(m);
        for(int i=0; i< m; i++){
            vector<pair<int,int>> column;
            for(int j =0; j< n ; j++){
                column.push_back({board[i][j], j});
            }
            sort(column.begin(), column.end());
            for(int j = n-1; j >= n-3; j--){
                cd[i].push_back(column[j]);
            }
        }
        long long ans = -1e18;
        for(int i=0; i<m; i++){
            int firstInd = cd[i][0].second;
            long long firstVal = cd[i][0].first;

            for(int j =0; j< m; j++){
                if( i != j ){
                    int ind = 0;
                    while(ind < cd[j].size() && cd[j][ind].second == firstInd) ind++;
                    if(ind >= cd[j].size()) continue;

                    int secondInd = cd[j][ind].second;
                    long long secondVal = cd[j][ind].first;

                    for(int k =0; k < m; k++){
                        if(i != k && j != k){
                            ind = 0;
                            while(ind < cd[k].size() && (cd[k][ind].second == firstInd || cd[k][ind].second == secondInd)) ind++;
                            if(ind >= cd[k].size()) continue;

                            int thirdInd = cd[k][ind].second;
                            long long thirdVal = cd[k][ind].first;

                            long long total = firstVal + secondVal + thirdVal;
                            ans = max(ans, total);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
