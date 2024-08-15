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
    int foo(TreeNode *root, int &cam)
    {
        if(!root) return 1;
        int left = foo(root->left, cam);
        int right = foo(root->right, cam);
        if(!left or !right){
            cam++;
            return 2;
        }
        return max(left, right)-1;
    }
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        int cam = 0;
        if(foo(root, cam) == 0)
            cam++;
        return cam;
    }
};