class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[26]={0};
        for(int i =0; i< s.length();i++){
            m[s[i]-'a']++;
        }
        bool vis[26] = {false};
        string res ="";
        for(int i =0; i< s.length(); i++){
            m[s[i]-'a']--;
            if(!vis[s[i]-'a']){
                while (res.size()>0 && res.back()>s[i] && m[res.back()-'a'] > 0) {
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