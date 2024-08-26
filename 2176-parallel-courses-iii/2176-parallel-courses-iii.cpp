class Solution {
public:
    stack<int> toposort;
    vector<vector<int>> adj;
    vector<bool> vis;
    void dfs(int i){
        vis[i] = true;
        for(auto it:adj[i]){
            if(!vis[it])
                dfs(it);
        }
        // toposort.push_back(i);
        toposort.push(i);
    } 
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        adj.resize(n);
        vis.resize(n, false);
        vector<vector<int>> adj2(n);
        for(auto &it:relations){
            it[0]--;it[1]--;
            adj[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        // reverse(toposort.begin(), toposort.end());
        vector<int> dp(n);
        while(toposort.size()){
            int i = toposort.top();
            toposort.pop();
            int maxprev = 0;
            for(auto &it:adj2[i]){
                maxprev = max(maxprev, dp[it]);
            }    
            dp[i] = maxprev + time[i];
        }      
        return *max_element(dp.begin(), dp.end());
    }
};