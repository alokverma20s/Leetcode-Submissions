class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> st;
        int curr = 0;
        int cnt  = 0;
        for(auto i: banned) st.insert(i);

        for(int i=1; i<= n; i++){
            if(st.find(i) != st.end()){
                continue;
            }
            if((curr+ i) <= maxSum)
                cnt++, curr+=(i);
        }
        return cnt;
    }
};