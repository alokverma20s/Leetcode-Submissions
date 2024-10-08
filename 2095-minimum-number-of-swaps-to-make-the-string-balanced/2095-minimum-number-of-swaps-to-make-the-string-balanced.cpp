class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int opening = 0, closing = 0;
        int cnt = 0;
        for(int i=0; i< s.length(); i++){
            if(s[i] == '[') st.push(s[i]);
            else{
                if(!st.empty()) st.pop();
                else cnt++;
            }
        }
        return (cnt+1)/2;
    }
};