class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        size_t n = nums.size();
        vector<int> dp(nums);
        multiset<int> st;
        dp[0] = nums[0];
        st.insert(-dp[0]);
        for(int i=1; i<n; i++){
            auto it = *st.begin();
            if(-it > 0){
                dp[i] = max(dp[i], -it+nums[i]);
            }
            st.insert(-dp[i]);
            if(i >= k){
                st.erase(st.find(-dp[i-k]));
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};