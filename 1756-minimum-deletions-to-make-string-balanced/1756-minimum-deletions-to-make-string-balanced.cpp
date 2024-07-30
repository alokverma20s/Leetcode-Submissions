class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int acnt[n], bcnt[n];
        int temp= 0;
        for(int i=0; i < n; i++){
            bcnt[i] = temp;
            if(s[i] =='b') temp++;
        }
        temp = 0;
        for(int i = n-1; i>=0; i--){
            acnt[i] = temp;
            if(s[i] =='a') temp++;
        }
        int minDel = n;
        for(int i =0; i< n; i++){
            minDel = min(minDel , acnt[i]+ bcnt[i]);
        }
        return minDel;
    }
};