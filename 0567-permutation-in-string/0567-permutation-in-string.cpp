class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int i=0;
        sort(s1.begin(), s1.end());

        for(int k = 0; k<= m-n; k++){
            string temp = s2.substr(i, n);
            i++;
            sort(temp.begin(), temp.end());
            // cout<< s1<<" "<<temp<<endl;
            if(s1 == temp) return true;
        }
        return false;
    }
};