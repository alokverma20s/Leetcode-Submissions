class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int cnt=0;
        for(int i=0; i< s.length(); i++){
            if(s[i] =='(') st.push(s[i]);
            else{
                if(!st.empty()) st.pop();
                else cnt++;
            }
        }
        cnt += st.size();
        return cnt;
    }
};