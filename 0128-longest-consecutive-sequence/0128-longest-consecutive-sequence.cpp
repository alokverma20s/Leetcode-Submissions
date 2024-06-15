class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st;
        for(int i: nums) st.insert(i);
        int ans = 1;

        for(auto i: st){
            if(st.find(i-1) == st.end()){
                int cnt =1;
                int cur = i;
                while(st.find(cur+1) != st.end()){
                    cnt++;
                    cur = cur +1;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};