class Solution {
public:
    vector<vector<vector<int>>> adj;
    vector<int> vis;
    int ans = 0;
    void dfs(int i, int rem, int sum, vector<int> &values){
        if(!vis[i]){
            sum += values[i];
        }
        vis[i] += 1;
        if(i == 0){
            ans = max(ans, sum);
        }
        for(auto &it:adj[i]){
            if(it[1] <= rem){
                // cout << i << " " << it[0] << " " << it[1] << endl;
                dfs(it[0], rem-it[1], sum, values);
            }
        }
        vis[i] -= 1;
    }   
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        adj.resize(n);
        vis.resize(n, false);
        for(auto &it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        dfs(0, maxTime, 0, values);
        return ans;
    }
};