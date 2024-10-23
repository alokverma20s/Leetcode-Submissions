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
#define pii pair<int, int>
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;
        queue<TreeNode*> q;
        q.push(root);
        pii found = {-1,-1};
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i< size; i++){
                TreeNode* top = q.front();
                if(top->val == x) found.first = level;
                if(top->val == y) found.second = level;
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                if(top->left && top->right && (top->left->val == x || top->left->val == y) && (top->right->val == y || top->right->val ==x)) return false;
            }
            if(found.first != found.second) return false;
            level++;
        }
        return true;
    }
};