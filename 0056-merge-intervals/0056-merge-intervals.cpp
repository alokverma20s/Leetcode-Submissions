class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int, int>> v;
        for(auto i: intervals){
            v.push_back({i[0], i[1]});
        }
        sort(v.begin(), v.end());

        vector<vector<int>> ans;
        int start  = v[0].first;
        int end = v[0].second;
        for(int i=1; i< v.size(); i++){
            if(end >= v[i].first){
                end = max(end, v[i].second);
            }
            else{
                ans.push_back({start, end});
                start = v[i].first;
                end = v[i].second;
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};