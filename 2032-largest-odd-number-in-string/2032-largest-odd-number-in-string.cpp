class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length()-1;

        while(n >= 0){
            if((num[n]-'0') & 1)
                return num;
            num.pop_back();
            n--;
        }
        return num;
    }
};