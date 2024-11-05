class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        vector<pair<int, char>> p;
        for(auto i: m) p.push_back({i.second, i.first});
        sort(p.rbegin(), p.rend());
        string ans;
        for(auto i:p){
            for(int j=0;j<i.first;j++){
                ans.push_back(i.second);
            }
        }
        return ans;
    }
};