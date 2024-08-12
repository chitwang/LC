class Solution {
public:
    int countVowelPermutation(int n) {
        const int mod = 1e9+7;
        // a e
        // e a/i
        // i a/e/o/u
        // o i/u
        // u a
        vector<vector<int>> dp(n, vector<int> (5,0));
        for(int i=0;i<5;i++)
            dp[0][i] = 1;
        for(int i=1;i<n;i++){
            dp[i][0] = ((dp[i-1][1] + dp[i-1][2])%mod + dp[i-1][4])%mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%mod;
            dp[i][2] = (dp[i-1][1] + dp[i-1][3])%mod;
            dp[i][3] = dp[i-1][2];
            dp[i][4] = (dp[i-1][3] + dp[i-1][2])%mod;
        }
        int ans = 0;
        for(int j=0;j<5;j++){
            cout << dp[n-1][j] << " " ;
            ans = (ans + dp[n-1][j])%mod;
        }
        return ans;
    }
};