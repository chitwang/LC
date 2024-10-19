struct Trie{
    vector<Trie*> children;
    int count = 0;

    Trie() : children(2, nullptr) {} 
};

Trie *newn() {
    Trie *n = new Trie();
    return n;
}

void insert(Trie *root, int num) {
    Trie *cur = root;
    for(int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(!cur->children[bit]) {
            cur->children[bit] = newn();
        }
        cur->children[bit]->count++;
        cur = cur->children[bit];
    }
}

void delete_t(Trie *root, int num) {
    Trie *cur = root;
    vector<Trie*> path;
    for(int i = 30; i >= 0; i--) {
        int bit = (num >> i) & 1;
        path.push_back(cur);
        cur = cur->children[bit];
    }
    // path.push_back(cur); 
    reverse(path.begin(), path.end());
    for(int i = 0; i <= 30 ; i++) {
        int bit = (num >> i) & 1;
        Trie *node = path[i];
        if(node->children[bit]) {
            node->children[bit]->count--;
            if(node->children[bit]->count == 0) {
                delete node->children[bit];
                node->children[bit] = nullptr;
            }
        }
    }
}

int maxor(Trie *root, int num){
    Trie *cur = root;
    int ans = 0;
    for(int i=30;i>=0;i--){
        int bit = (num >> i) & 1;
        if(cur->children[1-bit] and cur->children[1-bit]->count){
            ans = ans + (1 << i);
            cur = cur->children[1-bit];
        }
        else{
            cur = cur -> children[bit];
        }
    }
    return ans;
}

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = 0;
        Trie *root = newn();
        int ans = 0;
        // for(int i=0;i<n;i++){
        //     cout << nums[i] << " ";
        // }
        // cout << endl;
        for(int i=0;i<n-1;i++){
            while(r < n and nums[r] <= 2*nums[i]){
                insert(root, nums[r]);
                r++;
            }
            while(l < i){
                delete_t(root, nums[l]);
                l++;
            }
            // cout << i <<  " " << l << " " << r << endl;;
            ans = max(ans, maxor(root, nums[i]));
        }
        return ans;
    }
};