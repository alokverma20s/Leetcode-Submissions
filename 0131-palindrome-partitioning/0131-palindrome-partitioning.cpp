class Solution {
    bool isPal(string s, int start, int end){
        while(start<=end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void fun(string s, int i, vector<string> &path, vector<vector<string>> &ans){
        if(i == s.length()){
            ans.push_back(path);
            return ;
        }

        for(int j=i; j< s.length(); j++){
            if(isPal(s, i, j)){
                path.push_back(s.substr(i, j-i+1));
                fun(s, j+1, path, ans);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        fun(s, 0, path, ans);
        return ans;
    }
};