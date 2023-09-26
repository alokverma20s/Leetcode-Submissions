class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> m;
        for(int i =0; i< s.length();i++){
            m[s[i]]++;
        }
        bool vis[26] = {false};
        string res ="";
        for(int i =0; i< s.length(); i++){
            m[s[i]]--;
            if(!vis[s[i]-'a']){
                while (res.size()>0 && res.back()>s[i] && m[res.back()] > 0) {
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        return res;
        
    }
};