class Solution {
public:
    int dp[15][17000];
    int helper(vector<int> &nums1, vector<int> &nums2, int i, int mask){
        if(i >= nums1.size()){
            return 0;
        }
        if(dp[i][mask] != -1)
            return dp[i][mask];
        int ans = 1e9;
        for(int j=0;j<nums2.size();j++){
            if(mask&(1<<j)) continue;
            ans = min(ans, helper(nums1, nums2, i+1, mask|(1<<j)) + (nums1[i]^nums2[j]));
        }
        return dp[i][mask]=ans;
    }
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        return helper(nums1, nums2, 0, 0);
    }
};