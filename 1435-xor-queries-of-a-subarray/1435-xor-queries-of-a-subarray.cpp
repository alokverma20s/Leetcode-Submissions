class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> v(arr.size());
        v[0]= arr[0];
        for(int i=1; i<arr.size(); i++) v[i] = v[i-1]^arr[i];

        int m = q.size();
        vector<int> ans(m);
        for(int i=0; i< m; i++){
            if(q[i][0] > 0)
                ans[i] = v[q[i][1]] ^v[q[i][0]-1]; 
            else ans[i] = v[q[i][1]];
        }
        return ans;
    }
};