class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
        }
        for(int len = 2;len<=n;len++){
            for(int i=0;i<n;i++){
                if(len+i-1 >= n)
                    break;
                dp[i][len+i-1] = dp[i][len+i-2] ^ dp[i+1][len+i-1]; 
            }
        }
        for(int len=2; len<=n;len++){
            for(int i=0;i<n;i++){
                if(len+i-1 >= n)
                    break;
                dp[i][len+i-1] = max({dp[i][len+i-1], dp[i][len+i-2], dp[i+1][len+i-1]}); 
            }
        }
        vector<int> ans;
        for(auto &it:queries){
            ans.push_back(dp[it[0]][it[1]]);
        }
        return ans;
    }
};