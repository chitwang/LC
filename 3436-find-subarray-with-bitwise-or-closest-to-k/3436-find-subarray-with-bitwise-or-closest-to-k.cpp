class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        vector<set<int>> dp(n);
        dp[0].insert(nums[0]);
        for(int i=1;i<n;i++){
            dp[i].insert(nums[i]);
            for(auto it:dp[i-1]){
                dp[i].insert(it|nums[i]);
            }
        }
        int diff = 1e9;
        for(int i=0;i<n;i++){
            for(auto it:dp[i]){
                diff = min(diff, abs(it-k));
            }
        }
        return diff;
    }
};