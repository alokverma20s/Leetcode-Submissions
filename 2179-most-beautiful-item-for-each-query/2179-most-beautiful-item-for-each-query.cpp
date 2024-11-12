class Solution{
    public:
        vector<int> maximumBeauty(vector<vector < int>> &items, vector< int > &queries){
           	// Sort items by their price (0th index) so we can use binary search
            sort(items.begin(), items.end());

           	// Store the original indices of queries so we can restore the result order later
            vector<pair<int, int>> v;
            int n = queries.size();
            for (int i = 0; i < n; i++)
                v.push_back({ queries[i],
                    i });
            sort(v.begin(), v.end());	// Sort queries by value for efficient processing

            vector<int> ans(n, 0);	// Result array initialized to 0
            int max_beauty = 0;
            int j = 0;

           	// Traverse sorted queries and update `max_beauty` based on available items
            for (int i = 0; i < n; i++){
                int query = v[i].first;
                int original_index = v[i].second;

               	// Update max_beauty with items that have a price <= current query
                while (j < items.size() && items[j][0] <= query){
                    max_beauty = max(max_beauty, items[j][1]);
                    j++;
                }

               	// Set the maximum beauty for the current query
                ans[original_index] = max_beauty;
            }

            return ans;
        }
};