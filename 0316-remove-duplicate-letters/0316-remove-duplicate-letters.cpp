class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> visited;

        for(int i: s) freq[i]++, visited[i] = false;
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            // cout<<s[i]<<" "<<freq[s[i]]<< " ";
            while(!st.empty() && st.top() > s[i] && freq[st.top()] > 0 && visited[s[i]] == false){
                visited[st.top()] = false;
                // cout<<"Removed "<<st.top()<<" ";
                st.pop();
            }
            if(visited[s[i]] == false){
                // cout<<"Pushed "<<s[i]<<" ";
                visited[s[i]] = true;
                st.push(s[i]);
            }
            // else cout<<"Skipped "<<s[i]<<" ";
            // cout<<endl;
            freq[s[i]]--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};