class Solution {
public:
    int minimumDeletions(string s) {
        int acnt = 0;
        int i =0;
        while(i< s.length()){
            if(s[i] == 'a')
                acnt++;
            i++;
        }
        int bcnt = 0;
        int minDel = s.length();

        for(int i=0; i<s.length(); i++){
            if(s[i]=='a') acnt--;
            minDel = min(minDel, acnt + bcnt);
            if(s[i] =='b') bcnt++;
        }
        return minDel;
    }
};