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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        vector<int> ans;
        if(!root)
            return ans;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode *x = q.front();
                q.pop();
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                if(!sz){
                    ans.push_back(x->val);
                }
            }
        }
        return ans;
    }
};