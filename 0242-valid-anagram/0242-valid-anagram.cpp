class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> ms, mt;
        for(int i=0; i< s.length(); i++) ms[s[i]]++;
        for(int i=0; i< t.length(); i++) mt[t[i]]++;
        return ms == mt;

    }
};