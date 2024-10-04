#define ll long long
class Solution {
public:
    ll dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int target = skill[0] + skill[n-1];


        ll totalChemistry = ((ll)skill[0] * (ll)skill[n-1]);
        for(int i=1; i< n/2;  i++){
            int temp = skill[i] + skill[n-1-i];

            if(temp != target) return -1;
            totalChemistry += ((ll)skill[i] * (ll)skill[n-i-1]);
        }
        return totalChemistry;
    }
};