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
#define pnn pair<TreeNode*, TreeNode*> 
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root == NULL) return NULL;
        vector<int> sum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int temp = 0;
            for(int i=0; i< size; i++){
                TreeNode* top = q.front();
                q.pop();
                temp += top->val;
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            sum.push_back(temp);
        }
        sum.push_back(0);
        TreeNode* ans = new TreeNode(0);
        queue<pnn> qp;
        qp.push({root, ans});
        int j= 1;
        while(!qp.empty()){
            int size = qp.size();
            for(int i=0; i< size; i++){
                pnn top = qp.front();
                qp.pop();
                // cout<< top.first->val<<" "<<top.second->val<<" "<<sum[j]<<endl;
                int temp = 0;
                if(top.first->left){
                    temp+= top.first->left->val;
                }
                if(top.first->right){
                    temp+= top.first->right->val;
                    top.second->right = new TreeNode(sum[j] - temp);
                    qp.push({top.first->right, top.second->right});
                }
                if(top.first->left){
                    top.second->left = new TreeNode(sum[j] - temp);
                    qp.push({top.first->left, top.second->left});
                }
            }
            j++;
        }
        return ans;
    }
};