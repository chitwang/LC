class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> adj2;
    vector<bool> vis;
    vector<int> topo;
    void dfs(int i){
        vis[i] = true;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it);
            }
        }
        topo.push_back(i);
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        adj.resize(n);
        adj2.resize(n);
        vis.resize(n, false);
        for(auto &ed:edges){
            if(ed[0] == ed[1])
                return -1;
            adj[ed[0]].push_back(ed[1]);
            adj2[ed[1]].push_back(ed[0]);
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i);
                // break;
            }
        }
        // dfs(0);
        reverse(topo.begin(), topo.end());
        map<int, int> mp;
        for(int i=0;i<n;i++)
            mp[topo[i]] = i;
        for(auto &ed:edges){
            if(mp[ed[0]] >= mp[ed[1]]){
                return -1;
            }
        }
        vector<vector<int>> dp(n, vector<int>(26,0));
        int maxi = 1;
        for(int i=0;i<n;i++){
            if(adj2[i].empty())
                dp[i][colors[i]-'a'] = 1;
        }
        for(auto &v:topo){
            for(auto &it:adj2[v]){
                for(int i=0;i<26;i++){
                    dp[v][i] = max(dp[v][i], dp[it][i] + (colors[v] == 'a'+i));
                    maxi = max(maxi, dp[v][i]);
                }
            }
        }
        return maxi;
    }
};