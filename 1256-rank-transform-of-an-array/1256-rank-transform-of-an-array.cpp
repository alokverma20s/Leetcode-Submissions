class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> v;
        for(int i=0; i< arr.size(); i++){
            v.push_back({arr[i], i});
        }
        sort(v.begin(), v.end());
        int j=0;
        int prev = INT_MIN;
        for(int i=0; i< arr.size(); i++){
            if(prev == v[i].first) v[i].first = j;
            else{
                prev =v[i].first;
                v[i].first = ++j;
            }
        }
        vector<int> ans(arr.size());
        for(int i=0; i<arr.size(); i++){
            ans[v[i].second] = v[i].first;
        }
        return ans;
    }
};