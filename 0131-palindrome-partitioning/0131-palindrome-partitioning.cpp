class Solution {
    bool checkPallindrome(string s, int start, int end){
        int n = s.length();
        while(start< end)
            if(s[start++] != s[end--]) return false;
        return true;
    }
    vector<vector<string>> ans;
    void solve(string s, int i, vector<string> &ds){
        if(i == s.length()){
            ans.push_back(ds);
            return;
        }

        for(int ind = i; ind < s.length(); ind++){
            if(checkPallindrome(s, i, ind)){
                ds.push_back(s.substr(i, ind - i +1));
                solve(s, ind+1, ds);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        solve(s, 0, ds);
        return ans;
    }
};