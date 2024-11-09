class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> b(x);
        vector<int> idx(64, 64);
        int j=0;
        for(int i =0; i < 64; i++){
            if(b[i] == 0)
                idx[j++] = i;
        }

        n-=1;
        bitset<64> rem(n);

        j= 0;
        for(int i=0; i< 64 && idx[j] < 64; i++){
            b[idx[j]]= rem[i];
            j++;
        }

        return b.to_ulong();
    }
};