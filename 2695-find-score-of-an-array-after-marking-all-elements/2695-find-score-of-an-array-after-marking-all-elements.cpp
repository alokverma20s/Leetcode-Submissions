class Solution{
    struct compare{
        bool operator()(const pair<int, int> &p1, const pair<int, int> &p2){
            if (p1.first == p2.first) return p1.second > p2.second;	// Compare second elements if first elements are equal 
            return p1.first > p2.first;	// Compare first elements 
        }
    };
    public:
        long long findScore(vector<int> &nums){
            int n = nums.size();
            priority_queue<pair<int, int>, vector< pair<int, int>>, compare> st;
            for (int i = 0; i < n; i++){
                st.push({ nums[i], i });
            }
            vector<bool> mark(n, false);

            long long ans = 0;

            while(!st.empty()){
                pair<int, int> t = st.top();
                st.pop();
                if(!mark[t.second]){
                    ans += t.first;
                    if(t.second+ 1 < n) mark[t.second+1] = true;
                    if(t.second -1 >=0) mark[t.second -1 ] = true;
                    mark[t.second] = true;
                }
            }
            return ans;
        }
};