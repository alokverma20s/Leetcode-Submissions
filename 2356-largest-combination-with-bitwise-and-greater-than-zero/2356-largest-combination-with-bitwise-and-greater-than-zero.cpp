class Solution {
public:
    int largestCombination(vector<int>& c) {
        int n = c.size();
        vector<int> v(24, 0);

        for(int i: c){
            int sh = 0;
            while(i){
                v[sh] += i & 1;
                sh++;
                i >>= 1;
            }
        }
        return *max_element(v.begin(), v.end());
    }
};