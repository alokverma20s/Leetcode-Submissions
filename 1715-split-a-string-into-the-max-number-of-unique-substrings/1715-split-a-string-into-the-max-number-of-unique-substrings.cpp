class Solution {
    void solve(string &s, int pos , int &maxCount, unordered_set<string> & st){
        if(pos >= s.length()){
            if(maxCount < st.size())
                maxCount = st.size();

            // for(auto i: st) cout<<i<< " ";
            // cout<<endl;
            return;
        }

        string subString;
        for(int i=pos; i<s.length(); i++ ){
            subString.push_back(s[i]);

            if(st.count(subString) == 0){
                st.insert(subString);
                solve(s, i+1, maxCount, st);
                st.erase(subString);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        int maxCount = 0;
        unordered_set<string> st;
        solve(s, 0, maxCount, st);
        return maxCount;
    }
};