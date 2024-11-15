class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        unordered_set<int> st;
        for(auto &it: nums){
            st.insert(it);
        }
        int ans = 0;
        int m = *max_element(nums.begin(), nums.end());
        for(int i=1; i<= m; i++){
            int g = 0;
            for(int j=i; j<=m; j+= i){
                if(st.count(j))
                    g = __gcd(g, j);
            }
            ans += (g == i);
        }
        return ans;
    }
};