class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> operation;
        stack<char> st;
        bool ans = 0;
        int i=0;
        while(i < expression.length()){
            if(expression[i] == '!' || expression[i] == '|' || expression[i] == '&') operation.push(expression[i]);
            else if(expression[i] == '(' || expression[i] == 'f' || expression[i] == 't') st.push(expression[i]);

            else if(expression[i] == ')'){
                bool temp = (operation.top() == '|' ? 0: 1);
                while(st.top() != '('){
                    if(operation.top() == '|')
                        temp = temp | (st.top() == 'f' ? 0: 1);
                    else if(operation.top() == '&') 
                        temp = temp & (st.top() == 'f' ? 0: 1);
                    else
                        temp = !(st.top() == 'f' ? 0: 1);
                    st.pop();
                }
                st.pop();
                st.push(temp ? 't': 'f');
                operation.pop();
                if(operation.empty()) return st.top() == 'f' ? 0: 1;
            }
            i++;
        }
        return ans;
    }
};