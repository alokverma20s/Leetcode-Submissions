#define ll long long
class Solution {
public:
    ll dividePlayers(vector<int>& skill) {
        int n = skill.size();
        ll sum = accumulate(skill.begin(), skill.end(), 0ll);

        ll ans = 0;
        unordered_map<int, int> mp;
        int cnt = 0;
        if(sum % (n/2) == 0){
            ll target = sum/(n/2);
            for(int i=0; i<n; i++){
                int temp = target - skill[i];
                if(mp.find(temp) != mp.end() && mp[temp] != 0){
                    mp[temp]--;
                    cnt++;
                    ans += (temp * skill[i]);
                }
                else{
                    mp[skill[i]]++;
                }

            }
        }
        if(cnt == n/2) return ans;
        return -1;
    }
};