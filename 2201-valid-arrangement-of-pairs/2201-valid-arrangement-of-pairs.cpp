class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;
        int startNode = -1, endNode = -1;

        for (auto it : pairs) {
            int fi = it[0], se = it[1];
            adj[fi].push_back(se);
            outdegree[fi]++;
            indegree[se]++;
        }

        for (auto it : adj) {
            int node = it.first;
            if (outdegree[node] - indegree[node] == 1) {
                startNode = node;
            } else if (indegree[node] - outdegree[node] == 1) {
                endNode = node;
            }
        }

        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        vector<vector<int>> ans;
        stack<int> stk;
        stk.push(startNode);

        while (!stk.empty()) {
            int node = stk.top();
            if (!adj[node].empty()) {
                int next = adj[node].back();
                adj[node].pop_back();
                stk.push(next);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    ans.push_back({stk.top(), node});
                }
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
