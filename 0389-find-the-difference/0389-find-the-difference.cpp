class Solution {
public:
    char findTheDifference(string s, string t) {
        int num1=0, num2=0;
        for(int i=0;i<s.length();i++){
            num1+=(int)t[i];
            num2+=(int)s[i];
        }
        num1+=(int)t[t.length()-1];
        return (char)(num1-num2);
    }
};