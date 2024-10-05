class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);
        for (int i = 0; i < n; i++) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == s2Count[i]) matches++;
        }

        for (int i = 0; i < m - n; i++) {
            if (matches == 26) return true;

            int r = s2[i + n] - 'a', l = s2[i] - 'a';
            s2Count[r]++;
            if (s2Count[r] == s1Count[r]) matches++;
            else if (s2Count[r] == s1Count[r] + 1) matches--;

            s2Count[l]--;
            if (s2Count[l] == s1Count[l]) matches++;
            else if (s2Count[l] == s1Count[l] - 1) matches--;
        }

        return matches == 26;
    }
};
