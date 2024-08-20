class Solution {
public:
    vector<vector<int>> dp;
    const int mod = 1e9+7;
    int foo(int ind, int prev, vector<int> &nums){
        if(ind >= nums.size()){
            return 1;
        }
        if(dp[ind][prev] != -1){
            return dp[ind][prev];
        }
        int x= 0;
        for(int arr1 = prev;arr1 <= nums[ind]; arr1++){
            int arr2 = nums[ind]-arr1;
            if(ind == 0 or arr2 <= nums[ind-1]-prev){
                x = (x + foo(ind+1, arr1, nums))%mod;
            }
        }
        return dp[ind][prev] = x;
    }
    int countOfPairs(vector<int>& nums) {
        dp = vector<vector<int>> (nums.size(), vector<int>(55, -1));
        return foo(0, 0, nums);
    }
};