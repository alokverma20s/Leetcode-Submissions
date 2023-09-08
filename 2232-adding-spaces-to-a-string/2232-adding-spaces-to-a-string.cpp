class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans ;
        string temp;
        int j=0;
        for(int i =0; i< s.length(); i++){
            if(j < spaces.size() && spaces[j] == i){
                temp.push_back(' ');
                i--;
                j++;
            }
            else
                temp.push_back(s[i]);
        }
        return temp;
    }
};