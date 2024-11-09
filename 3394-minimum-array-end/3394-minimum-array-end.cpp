class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> b(x);
        int mst = 0;
        vector<int> idx(64, 64);
        int j=0;
        for(int i =0; i < 64; i++){
            if(b[i] == 1) {
                mst = i+1;
            }
            else{
                idx[j++] = i;
            }
        }
        int unsetbit = mst - b.count();
        n-=1;
        bitset<64> rem(n);
        // cout<<n<<" "<< "rem is "<< rem<<endl;

        j= 0;
        for(int i=0; i< 64 && idx[j] < 64; i++){
            // cout<<idx[j]<<" "<<rem[i]<<" ";
            b[idx[j]]= rem[i];
            // cout<<b<<" \n";
            j++;
        }
        return b.to_ulong();
    }
};