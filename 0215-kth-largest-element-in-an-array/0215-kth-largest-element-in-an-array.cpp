class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> pq;
        for(auto it:nums){
            pq.insert(it);
        }
        auto it = pq.rbegin();
        while(--k){
            it++;
        }
        return *it;
    }
};