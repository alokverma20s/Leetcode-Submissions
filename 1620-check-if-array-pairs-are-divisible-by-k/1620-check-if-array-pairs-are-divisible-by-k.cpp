class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> st;
        for(int i: arr) {
            st[(i % k + k) % k]++;  // Ensure non-negative remainders
        }
        for(auto& i : st) {
            if(i.first == 0) {
                if(i.second % 2 != 0) return false;
            } else {
                if(st[i.first] != st[k - i.first]) return false;
            }
        }
        return true;
    }
};
