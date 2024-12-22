class Solution {
public:
    vector<vector<int>> adj;
    int ans = 1;
    int dfs(int i, int p, vector<int> &values, int k){
        int sum = values[i]%k;
        for(auto &it: adj[i]){
            if(it != p){
                int x = dfs(it, i, values, k);
                sum = (sum + x)%k;
                if(x == 0)
                    ans++;
            }
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        for(auto &ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        dfs(0, -1, values, k);
        return ans;
    }
};