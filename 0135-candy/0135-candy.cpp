class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n == 1)
            return 1;
        vector<pair<int, int>> v;
        for(int i=0; i< n; i++){
            v.push_back({ratings[i],1});
        }
        for(int k =0; k< 2;k++){
            for(int i=0; i< n;i++){
                if( i == 0){
                    if(v[i].first > v[i+1].first && v[i].second <= v[i+1].second){
                        v[i].second = v[i+1].second+1;
                    }
                }else if(i == n-1){
                    if((v[i].first > v[i-1].first) && (v[i].second <= v[i].second)){
                        v[i].second = v[i-1].second+1;
                    }
                }
                else{
                    if(v[i-1].first < v[i].first){
                        if(v[i-1].second >= v[i].second){
                            v[i].second = v[i-1].second+1;
                        }
                    }
                    if(v[i].first > v[i+1].first){
                        if(v[i-1].second >= v[i].second){
                            v[i].second = v[i+1].second+1;
                        }
                    }
                }
            }
            for(auto i: v){
                cout<<i.second<<" ";
            }
            cout<<endl;
            reverse(v.begin(), v.end());
        }
        int ans =0;
        for(auto i: v)
            ans += i.second;
        return ans;
    }
};