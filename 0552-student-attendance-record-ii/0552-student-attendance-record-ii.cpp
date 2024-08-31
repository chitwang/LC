class Solution {
public:
    vector<vector<vector<int>>> dp;
    const int mod = 1e9+7;
    int foo(int n, int a, int l){
        if(dp[n][a][l] != -1){
            return dp[n][a][l];
        }
        if(n == 0){
            return 1;
        }
        int x = 0;
        if(a == 0){
            x = (x + foo(n-1, a+1, 0))%mod;
        }
        x = (x + foo(n-1, a, 0))%mod;
        if(l < 2){
            x = (x + foo(n-1, a, l+1))%mod;
        }
        return dp[n][a][l] = x;
    }
    int checkRecord(int n) {
        dp = vector<vector<vector<int>>>(n+5, vector<vector<int>>(2, vector<int>(3, -1)));
        return foo(n, 0, 0);
    }
};