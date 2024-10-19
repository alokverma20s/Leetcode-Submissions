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
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex){
        int n = inorder.size();
        for(int i=0; i< n; i++) nodeToIndex[inorder[i]] = i;
    }
    TreeNode* solve(vector<int>& pre, vector<int>& in, int &index, int inStart, int inEnd, int n, map<int, int> &nodeToIndex){
        if(index >= n || inStart > inEnd) return NULL;

        int element = pre[index++];

        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root->left = solve(pre, in, index, inStart, position - 1, n, nodeToIndex);
        root->right = solve(pre, in, index, position+1, inEnd, n, nodeToIndex);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        int preOrderStart = 0;
        int n = inorder.size();
        createMapping(inorder, mp);
        return solve(preorder, inorder, preOrderStart, 0, n-1, n, mp);
    }
};