class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.length();
        int i=0, j =0, cnt = 1;
        char prev='^';

        while(i < n){
            cout<< prev<<" "<< sentence[i]<<" "<<searchWord[j]<<" \n";
            if((prev == '^' || prev == ' ') && sentence[i] == searchWord[j]){
                while( j < m && sentence[i] == searchWord[j]){
                    i++; j++;
                }
                if(j == m) return cnt;
            }
            if(sentence[i] == ' '){
               cnt++; 
            } 
            prev = sentence[i];
            i++;
            j=0;
        }
        return -1;
    }
};