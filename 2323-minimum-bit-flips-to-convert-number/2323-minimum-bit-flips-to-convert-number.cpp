class Solution {
public:
    int minBitFlips(int start, int goal) {
        int change = start ^ goal;
        bitset<32> a(change);
        return a.count();
    }
};