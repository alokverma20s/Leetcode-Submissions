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
#define ll long long
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> pq;
        if(root == NULL) return -1;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int size =  q.size();
            ll temp = 0;
            for(int i=0; i< size; i++){
                TreeNode* front = q.front();
                q.pop();
                temp += (ll)(front->val);
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            pq.push_back(temp);
        }
        sort(pq.rbegin(), pq.rend());
        if(k > pq.size()) return -1;
        return pq[k-1];
    }
};