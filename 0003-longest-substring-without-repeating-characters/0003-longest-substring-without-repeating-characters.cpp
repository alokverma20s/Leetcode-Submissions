class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        int ans =1;
        unordered_map<char, int> st;
        int left = 0;
        int right = 0;
        int n = s.length();

        while( right < n){
            if(st.find(s[right]) != st.end() && st[s[right]] >= left){
                left = st[s[right]]+1;
            }
            ans = max(ans , right - left +1);
            st[s[right]] = right;
            right++;
        }
        return ans;
    }
};