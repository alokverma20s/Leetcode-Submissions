class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.length();
        int left = 0;

        int a[3] = {0,0,0};

        for(int t=0; t< n; t++){
            a[s[t]-'a']++;
            if(a[0] >= k && a[1] >= k && a[2] >= k){
                left = t+1;
                break;
            }
        }
        if(a[0] < k || a[1] < k || a[2] < k) return -1;

        int ans =  left;
        left--;
        int right = n-1;
        while(left >= 0){
            a[s[left]-'a']--;
            left--;

            while(left <= right && (a[0] < k || a[1] < k || a[2] < k)){
                a[s[right]-'a']++;
                right--;
            }
            ans = min(ans, n-(right-left));
        }
        return ans;
    }
};