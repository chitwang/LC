class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        size_t n = nums.size();
        long long ans = 0;
        int lbound = -1;
        int minp = -1, maxp = -1;
        for(int i=0;i<n;i++){
            if(nums[i] < minK or nums[i] > maxK){
                lbound = i;
            }
            if(nums[i] == minK){
                minp = i;
            }
            if(nums[i] == maxK){
                maxp = i;
            }
            ans += max(0, min(minp, maxp)-lbound);
        }
        return ans;
    }
};