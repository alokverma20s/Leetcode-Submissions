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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        if(root != NULL)
            st.push(root);
        vector<int> ans;
        while(!st.empty()){
            TreeNode * top = st.top();
            st.pop();
            if(top->right) st.push(top->right);
            if(top->left) st.push(top->left);

            ans.push_back(top->val);
        }
        return ans;
    }
};