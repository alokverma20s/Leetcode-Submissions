class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        int ans =1;
        unordered_set<char> st;
        int left = 0;
        int right = 0;
        int n = s.length();

        while( right < n){
            if(st.find(s[right]) == st.end()){
                ans = max(ans , right - left +1);
            }else{
                while(left < right && st.find(s[right]) !=st.end()){
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
            right++;
        }
        return ans;
    }
};