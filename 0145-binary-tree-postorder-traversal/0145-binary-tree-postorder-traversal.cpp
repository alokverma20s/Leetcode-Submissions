/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        if(root != nullptr) st.push(root);
        stack<int> s;
        vector<int> ans;
        TreeNode* node = root;

        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
            s.push(node->val);

        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};