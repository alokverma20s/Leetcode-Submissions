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
    int res = 0;
    pair<int, int> dfs(TreeNode* root){
        if(root == NULL)
            return {0,0};
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        int size = 1 + left.first  + right.first;
        int coins = root->val +  left.second + right.second;
        res += abs(size - coins);
        return {size, coins};
    }
public:
    int distributeCoins(TreeNode* root) {
        pair<int, int> temp = dfs(root);
        return res;
    }
};