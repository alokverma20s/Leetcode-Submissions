class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> st;
        for(int i: arr) {
            // printf("%d, %d, %d\n", i % k, (i % k + k), (i % k + k) % k);
            st[(i % k + k) % k]++;  // Ensure non-negative remainders
        }
        for(auto& i : st) {
            // cout<<i.first<<" "<<i.second<<endl;
            if(i.first == 0) {
                if(i.second % 2 != 0) return false;
            } else {
                if(st[i.first] != st[k - i.first]) return false;
            }
        }
        return true;
    }
};
