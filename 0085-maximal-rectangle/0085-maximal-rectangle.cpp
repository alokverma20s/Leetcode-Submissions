class Solution
{
    public:
        int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int ans = 0;
        h.push_back(0);
        for(int i=0; i< h.size(); i++){
            while(!st.empty() && h[st.top()] > h[i]){
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }            
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector < char>> &mat)
    {
        int r = mat.size();
        if (r == 0) return 0;
        int c = mat[0].size();
        int maxi = 0;
        vector<int> histo(c, 0);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == '1') histo[j] += 1;
                else histo[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(histo));
        }
        return maxi;
    }
};