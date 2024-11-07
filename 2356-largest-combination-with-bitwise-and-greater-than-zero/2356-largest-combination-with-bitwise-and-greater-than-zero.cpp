class Solution {
public:
    int largestCombination(vector<int>& c) {
        int n = c.size();
        vector<bitset<24>> v(n);

        for(int i=0; i< n; i++){
            bitset<24> temp(c[i]);
            v[i] = temp;
        }

        int ans = 0;
        for(int i=0; i<24; i++){
            int cnt = 0;
            for(int j=0; j< n; j++){
                // cout<< v[j][i]<<" ";
                if(v[j][i] == 1) cnt++;
            }
            // cout<<endl;
            ans = max(ans, cnt);
        }
        return ans;
    }
};