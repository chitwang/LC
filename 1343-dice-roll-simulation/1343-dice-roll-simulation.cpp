class Solution {
public:
    int dp[5001][7][16];
    int mod = 1e9+7;
    int foo(int n, int last, int cnt, vector<int> &maxroll)
    {
        if(n==0) return 1;
        if(dp[n][last][cnt] != -1)
            return dp[n][last][cnt];
        int ans = 0;
        for(int i=1;i<=6;i++){
            if(i == last and cnt > 0){
                ans = (ans + foo(n-1, i, cnt-1, maxroll))%mod;
            }
            else if(i != last){
                ans = (ans + foo(n-1, i, maxroll[i-1]-1, maxroll))%mod;
            }
        }
        return dp[n][last][cnt] = ans;
    }
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp, -1, sizeof(dp));
        return foo(n, 0, 0, rollMax);
    }
};