class Solution {
public:
    bool areSentencesSimilar(string s, string t) {
        int n = s.length(), m = t.length();

        if(n > m){
            swap(s, t);
            swap(n, m);
        }

        string temp="";
        vector<string> vs, vt;
        for(int i=0; i< n; i++){
            if(s[i] != ' ') temp.push_back(s[i]);
            else{
                vs.push_back(temp);
                temp = "";
            }
        }
        vs.push_back(temp);
        temp="";
        for(int i=0; i< m; i++){
            if(t[i] != ' ') temp.push_back(t[i]);
            else{
                vt.push_back(temp);
                temp = "";
            }
        }
        vt.push_back(temp);

        int i=0, j =0;
        while(i<vs.size() && j < vt.size() && vs[i] == vt[j]){i++; j++;}
        int pre = i;
        i= vs.size()-1;
        j = vt.size()-1;

        while(i>= 0 && j >= 0 && vs[i] == vt[j]){i--; j--;}
        int suf = vs.size()-i-1;

        cout<<pre << ' '<<suf;



        return suf + pre >= vs.size();
    }
};