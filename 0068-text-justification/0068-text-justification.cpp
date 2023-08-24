class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int length =0, i=0;
        vector<string> line;

        while(i < words.size()){
            if(length + line.size() + words[i].length() > maxWidth){
                int extraSpace = maxWidth - length;
                cout<<length<< " "<<extraSpace<<" ";
                int spaces = extraSpace /((1 > (line.size()-1))?1:line.size()-1);
                int remainder = extraSpace % ((1 > (line.size()-1))?1:line.size()-1);
                string temp="";
                cout<<spaces<<" "<<remainder<<" "<<endl;
                for(int j = 0; j < ((1 > line.size()-1)?1:line.size()-1); j++){
                    temp += line[j];
                    for(int k =0; k< spaces; k++)
                        temp.push_back(' ');
                    if(remainder){
                        temp.push_back(' ');
                        remainder--;
                    }
                }
                if(line.size() != 1)
                    temp+=line.back();
                res.push_back(temp);
                length = 0; line.clear();
            }
            line.push_back(words[i]);
            length += words[i].length();
            i++;
        }
        string temp="";
        for(int j=0; j < line.size(); j++){
            line[j].push_back(' ');
            temp += line[j];
        }
        temp.pop_back();
        int trailSpace = maxWidth - temp.length();
        for(int j=0; j< trailSpace; j++){
            temp.push_back(' ');
        }
        res.push_back(temp);
        return res;
    }
};