class Solution {
    int ans = 0;
    void find(string s, int i){

        ans ++;
        for(int j = i; j< s.length(); j++){
            if(i != j && s[i] == s[j])
                continue;
            swap(s[i], s[j]);
            find(s, i+1);
        }
    }
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        find(tiles, 0);
        return ans-1;
    }
};