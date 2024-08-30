class Solution {
public:
    vector<bool> vis;
    vector<vector<vector<int>>> adj;
    vector<int> comp;
    void dfs(int i, int c){
        vis[i] = true;
        comp[i] = c;
        for(auto &it:adj[i]){
            if(!vis[it[0]]){
                dfs(it[0], c);
            }
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vis.resize(n, false);
        adj.resize(n);
        comp.resize(n, -1);
        for(auto &ed:edges){
            adj[ed[0]].push_back({ed[1], ed[2]});
            adj[ed[1]].push_back({ed[0], ed[2]});
        }
        int c = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, c++);
            }
        }
        vector<int> dp(n, INT_MAX);
        for(auto &ed:edges){
            dp[comp[ed[0]]] &= ed[2];
        }
        vector<int> ans;
        for(auto &q:query){
            if(comp[q[0]] != comp[q[1]])
                ans.push_back(-1);
            else
                ans.push_back(dp[comp[q[0]]]);
        }
        return ans;
    }
};