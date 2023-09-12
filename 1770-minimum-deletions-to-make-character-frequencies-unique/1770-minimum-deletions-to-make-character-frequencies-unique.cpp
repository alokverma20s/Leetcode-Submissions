class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        for(int i =0; i< s.length(); i++){
            m[s[i]]++;
        }
        int cnt = 0;
        unordered_set<int> st;
        for(auto i: m){
            while(i.second != 0 && st.count(i.second)){
                i.second--;
                cnt++;
            }
            if(i.second != 0)
            st.insert(i.second);
        }
        return cnt;
        
    }
};