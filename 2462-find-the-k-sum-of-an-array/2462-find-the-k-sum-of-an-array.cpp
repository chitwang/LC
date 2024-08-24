class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        for(auto &it:nums){
            if(it >= 0){
                ans += it;
            }
            else{
                it = -it;
            }
        }
        sort(nums.begin(),nums.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({nums[0], 0});
        vector<long long> tmp;
        while(!pq.empty() and tmp.size() < k-1){
            auto x = pq.top();
            pq.pop();
            tmp.push_back(x.first);
            if(x.second < n-1){
                pq.push({x.first + nums[x.second+1], x.second+1});
                pq.push({x.first + nums[x.second+1] - nums[x.second], x.second+1});
            }
        }
        vector<long long> v = {ans};
        for(auto it:tmp){
            v.push_back(ans - it);
        }
        return v[k-1];
    }
};