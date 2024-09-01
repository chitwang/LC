class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        long long ans = 0;
        vector<int> st;
        int n = nums1.size();
        // vector<int> v(n);
        for(int i=0;i<n;i++){
            int y = nums1[i] - nums2[i];
            int x = y + diff;
            auto it = upper_bound(st.begin(), st.end(), x);
            ans += distance(st.begin(), it);
            st.insert(lower_bound(st.begin(), st.end(), y), y);
        }
        return ans;
    }
};