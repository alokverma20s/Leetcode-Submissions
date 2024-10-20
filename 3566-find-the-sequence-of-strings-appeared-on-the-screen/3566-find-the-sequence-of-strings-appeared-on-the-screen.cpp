class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        ans.push_back("a");
        int i =0;
        while(i < target.length()){
            string temp = ans.back();
            if(temp[i] != target[i]){
                temp[i] +=1;
                ans.push_back(temp);
            }else {
                temp.push_back('a');
                i++;
                if(i< target.length()) ans.push_back(temp);
            }
        }
        return ans;
    }
};