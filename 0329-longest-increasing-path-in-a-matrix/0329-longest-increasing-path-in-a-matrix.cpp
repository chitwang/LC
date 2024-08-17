class Solution {
    vector<vector<int>> dp;
    vector<vector<bool>> vis;
public:
    vector<vector<int>> getvert(int i, int j, vector<vector<int>> &matrix){
        vector<vector<int>> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        if(i < m-1 and matrix[i+1][j] > matrix[i][j]){
            ans.push_back({i+1,j});
        }
        if(j < n-1 and matrix[i][j+1] > matrix[i][j]){
            ans.push_back({i,j+1});
        }
        if(i > 0 and matrix[i-1][j] > matrix[i][j]){
            ans.push_back({i-1,j});
        }
        if(j > 0 and matrix[i][j-1] > matrix[i][j]){
            ans.push_back({i, j-1});
        }
        return ans;
    }
    void dfs(int i, int j, vector<vector<int>> &matrix){
        vis[i][j] = true;
        for(auto it:getvert(i, j, matrix)){
            if(!vis[it[0]][it[1]]){
                dfs(it[0], it[1], matrix);
            }
            dp[i][j] = max(dp[i][j], 1 + dp[it[0]][it[1]]);
        }
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp = vector<vector<int>> (matrix.size(), vector<int>(matrix[0].size(), 1));
        vis = vector<vector<bool>> (matrix.size(), vector<bool>(matrix[0].size(), false));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(!vis[i][j]){
                    dfs(i, j, matrix);
                }
            }
        }
        int ans = 0;
        for(auto it:dp){
            for(auto iter:it){
                ans = max(iter, ans);
            }
        }
        return ans;
    }
};