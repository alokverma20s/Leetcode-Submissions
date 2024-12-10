class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> top3(26, vector<int>(3, -1));

        char lst ='*';
        int win = 0;

        for(int i=0; i< s.length(); i++){
            if(lst == s[i]){
                win++;
                int t = s[i]-'a';
                vector<int> temp  = top3[t];
                if(temp[0] <= temp[1] && temp[0] <= temp[2] && win > temp[0]){
                    top3[t][0] = win;
                }
                else if(temp[1] <= temp[0] && temp[1] <= temp[2] && win > temp[1]){
                    top3[t][1] =win;
                }
                else if(temp[2] < win) top3[t][2] = win;
            }
            else{
                lst = s[i];
                win = 1;
                int t = s[i]-'a';
                vector<int> temp  = top3[t];
                if(temp[0] <= temp[1] && temp[0] <= temp[2] && win > temp[0]){
                    top3[t][0] = win;
                }
                else if(temp[1] <= temp[0] && temp[1] <= temp[2] && win > temp[1]){
                    top3[t][1] =win;
                }
                else if(temp[2] < win) top3[t][2] = win;
            }
        }
        int ans = -1;
        for(int i=0; i< 26; i++){
            // cout<< top3[i][0]<<" "<<top3[i][1]<<" "<<top3[i][2]<<endl;
            int t = min(top3[i][0], min(top3[i][1], top3[i][2]));
            ans = max(ans,t);
        }
        return ans;
    }
};