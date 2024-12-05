class Solution {
public:
    bool canChange(string start, string target) {
        int f = 0, s = 0;
        int n = start.length();

        while (f < n && s < n) {
            while (f < n && start[f] == '_') f++;
            while (s < n && target[s] == '_') s++;

            if (f == n || s == n) break;

            if (start[f] != target[s]) return false;

            if (start[f] == 'L' && f < s) return false;
            if (start[f] == 'R' && f > s) return false;

            f++;
            s++;
        }

        while (f < n && start[f] == '_') f++;
        while (s < n && target[s] == '_') s++;

        return f == n && s == n;
    }
};
