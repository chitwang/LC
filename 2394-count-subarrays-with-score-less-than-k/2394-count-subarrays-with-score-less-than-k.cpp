class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> pre(n, nums[0]);
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i=0;i<n;i++){
            int low = i;
            int high =n-1;
            int tmp = i-1;
            while(low <= high){
                int mid = (low + high) >> 1;
                long long curr = (pre[mid] - (i > 0 ? pre[i-1] : 0))*(mid - i+1);
                if(curr < k){
                    low = mid+1;
                    tmp = mid;
                }
                else{
                    high = mid - 1;
                }
            }
            ans += tmp - i + 1;
        }
        return ans;
    }
};