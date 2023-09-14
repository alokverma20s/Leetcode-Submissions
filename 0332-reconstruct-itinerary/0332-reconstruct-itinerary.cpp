class Solution {
    bool solve(unordered_map<string, vector<string>> &mp,int n, string curr, vector<string> &ans){
        if(ans.size() == n + 1)
            return true;
        if(!mp.count(curr))
            return false;
        vector<string> temp = mp[curr];

        for(int i=0; i< mp[curr].size(); i++){
            string st = mp[curr][i];
            ans.push_back(st);
            mp[curr].erase(mp[curr].begin()+i);

            if(solve(mp, n, st, ans))
                return true;
            
            mp[curr].insert(mp[curr].begin()+i, st);
            ans.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> mp;
        int n = tickets.size();
        sort(tickets.begin(), tickets.end());
        for(int i=0; i< n; i++){
            mp[tickets[i][0]].push_back(tickets[i][1]);
        }
        vector<string> ans;
        // for(auto i: mp){
        //     cout<<i.first<<" -> ";
        //     for(int j =0; j< i.second.size(); j++){
        //         cout<<i.second[j]<<", ";
        //     }
        //     cout<<endl;
        // }
        ans.push_back("JFK");
        bool temp = solve(mp, n, "JFK", ans);
        return ans;

        
    }
};