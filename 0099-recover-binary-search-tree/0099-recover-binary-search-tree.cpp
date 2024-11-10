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
    void recoverTree(TreeNode* root) {
        TreeNode* current = root;
        TreeNode* pre = nullptr;
        TreeNode* num1 = nullptr;
        TreeNode* num2 = nullptr;
        while(current){
            if(current->left){
                TreeNode* pred = current->left;
                while(pred->right && pred->right != current){
                    pred = pred->right;
                }
                if(!pred->right){
                    pred->right = current;
                    current = current->left;
                }
                else{
                    pred->right = nullptr;
                    if(pre){
                        if(num1 == nullptr && pre->val > current->val){
                            num1 = pre;
                        }
                        if(current->val < pre->val){
                            num2 = current;
                        }
                    }
                    pre = current;
                    current = current->right;
                }
            }
            else{
                if(pre){
                        if(num1 == nullptr && pre->val > current->val){
                            num1 = pre;
                        }
                        if(current->val < pre->val){
                            num2 = current;
                        }
                    }
                pre = current;
                current = current->right;
            }
        }
        int value = num1->val;
        num1->val = num2->val;
        num2->val = value;
        return;
    }
};

