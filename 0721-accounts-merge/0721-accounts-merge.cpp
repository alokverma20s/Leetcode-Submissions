class disjointSet{
    public:
    vector<int> size, parent;
    disjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]= i;
    }
    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_v == ulp_u) return;
        if(size[ulp_v] > size[ulp_u]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        disjointSet ds(n);
        for(int i=0; i<n; i++){
            bool merge = false;
            for(int j=1; j< accounts[i].size(); j++){
                if(mp.find(accounts[i][j]) == mp.end())
                    mp[accounts[i][j]] = i;
                else{
                    ds.unionBySize(mp[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> mergedList(n);
        for(auto it: mp)
            mergedList[ds.findUParent(it.second)].push_back(it.first);
        
        vector<vector<string>> ans;
        for(int i=0; i< n; i++){
            vector<string> temp;
            if(mergedList[i].size() == 0) continue;
            // temp.push_back(accounts[i][0]);
            for(auto i: mergedList[i]) temp.push_back(i);
            sort(temp.begin(), temp.end());
            vector<string> a;
            a.push_back(accounts[i][0]);
            a.insert(a.end(), temp.begin(), temp.end());
            ans.push_back(a);
        }
        return ans;
    }
};