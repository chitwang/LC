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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        
        q.push(root);
        int ans = -1e9;
        int lev = 1;
        int i=1;
        if(!root)
            return ans;
        while(!q.empty()){
            int sz = q.size();
            int sum = 0;
            while(sz--){
                TreeNode *x = q.front();
                q.pop();
                sum += x->val;
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
            }
            if(ans < sum){
                ans = sum;
                lev = i;
            }
            i++;
        }
        return lev;
    }
};