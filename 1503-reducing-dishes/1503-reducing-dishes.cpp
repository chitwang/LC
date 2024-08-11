class Solution {
public:
    vector<vector<int>> dp;
    int foo(int x, vector<int> &satisfaction, int i){
        if(i == satisfaction.size())
            return 0;
        if(dp[i][x] != -1){
            return dp[i][x];
        }
        return dp[i][x] = max(satisfaction[i] * x + foo(x+1, satisfaction, i+1), foo(x, satisfaction, i+1));
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        const int n = satisfaction.size();
        dp = vector<vector<int>> (n+1, vector<int>(n+1, -1));
        return foo(1, satisfaction, 0);
    }
};