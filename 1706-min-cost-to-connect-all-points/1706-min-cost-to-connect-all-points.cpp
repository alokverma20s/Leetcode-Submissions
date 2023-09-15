class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n =points.size();
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<n;i++){
            int u=points[i][0];
            int v= points[i][1];
            for(int j=i+1;j<n;j++){
                int w=points[j][0];
                int x=points[j][1];
                adj[i].push_back(make_pair(j,abs(u-w)+abs(v-x)));
                adj[j].push_back(make_pair(i,abs(u-w)+abs(v-x)));
            }
        }
        //for(auto i:adj ){
        //    cout<<i.first<<"->";
        //    for(auto j:adj[i.first])
        //        cout<<"("<<j.first<<","<<j.second<<")";
        //        cout<<endl;
        //}
        //return 0;
        vector<int> key(n);
        vector<bool> mst(n);
        vector<int> parent(n);
        for(int i=0;i<n;i++){
            key[i]=INT_MAX;
            parent[i]=-1;
            mst[i]=false;
        }
        parent[0]=-1;
        key[0]=0;

        for(int i=0;i<n;i++){
            int mini = INT_MAX;
            int u;
            for(int v=0;v<n;v++){
                if(!mst[v]&& key[v]< mini){
                    u=v;
                    mini=key[v];
                }
            }
            mst[u]=true;
            for(auto it: adj[u]){
                int v=it.first;
                int w=it.second;
                if(!mst[v] && w<key[v]){
                    key[v]=w;
                    parent[v]=u;
                }
            }
        }
        int ans=0;
        for(auto i: key)
            ans+=i;
        return ans;
    }
};