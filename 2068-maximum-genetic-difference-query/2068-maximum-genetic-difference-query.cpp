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
    vector<vector<int>> adj;
    vector<vector<pair<int,int>>> que;
    vector<int> ans;
    Trie *root;
    void dfs(int i, int p){
        // cout << "dfs " << i << endl;
        insert(root, i);
        for(auto &it:que[i]){
            ans[it.second] = maxor(root, it.first);
        }
        for(auto &it:adj[i]){
            if(it != p){
                dfs(it, i);
            }
        }
        delete_t(root, i);
        // cout << "delete " << i << endl;
    }
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        size_t n = parents.size();
        adj.resize(n);
        que.resize(n);
        ans.resize(queries.size());
        root = newn();
        for(size_t i =0; i<queries.size();i++){
            auto it = queries[i];
            que[it[0]].push_back({it[1], i});
        }
        int ro = 0;
        for(int i=0;i<n;i++){
            if(parents[i] != -1){
                adj[i].push_back(parents[i]);
                adj[parents[i]].push_back(i);
            }
            else{
                ro = i;
            }
        }
        dfs(ro, -1);
        return ans;
    }
};