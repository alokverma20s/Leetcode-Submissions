class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int left = 0;
        map<char, int> mp;
        int n = s.length();
        int cnt = 0;

        for(int i=0; i< n; i++){
            mp[s[i]]++;
            if(mp[s[i]] >= k){
                while(mp[s[i]] >= k){
                    cnt += n-i-1;
                    cnt++;
                    mp[s[left]]--;
                    left++;
                }
            }
        }
        return cnt;
    }
};