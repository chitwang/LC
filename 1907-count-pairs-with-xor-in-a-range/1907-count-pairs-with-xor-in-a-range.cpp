const int LEVEL = 16;

class node {
    public:
    int cnt = 0;
    node *children[2];
    node(){
        children[0] = children[1] = nullptr;
    }
    void insert(node *root, int n ){
        for(int i=LEVEL;i>=0;i--){
            bool x = n & (1 << i);
            if(!root->children[x]){
                root->children[x] = new node();
            }
            root->children[x]->cnt += 1;
            root = root->children[x];
        }
    }
};

class Solution {
public:
    int foo(node *root, int n, int k){
        int ans = 0;
        for(int i=LEVEL;i>=0 and root;i--){
            bool x = n & (1 << i);
            bool y = k & (1 << i);
            if(y == 0){
                root = root->children[x];
                continue;
            }
            if(root->children[x]){
                ans += root->children[x]->cnt;
            }
            root = root->children[1-x];
        }
        return ans;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        node *root = new node();
        int ans = 0;
        for(auto it:nums){
            ans += foo(root, it, high+1) - foo(root, it, low);
            root->insert(root, it);
        }
        return ans;
    }
};