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
    TreeNode* solve(vector<int>& post, vector<int>& in, int &index, int inStart, int inEnd, int n, map<int, int> &nodeToIndex){
        if(index <= -1 || inStart > inEnd) return NULL;

        int element = post[index--];

        TreeNode* root = new TreeNode(element);
        int position = nodeToIndex[element];

        root->right = solve(post, in, index, position+1, inEnd, n, nodeToIndex);
        root->left = solve(post, in, index, inStart, position - 1, n, nodeToIndex);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        int n = inorder.size();
        int postOrderStart = n-1;
        createMapping(inorder, mp);
        return solve(postorder, inorder, postOrderStart, 0, n-1, n, mp);
    }
};