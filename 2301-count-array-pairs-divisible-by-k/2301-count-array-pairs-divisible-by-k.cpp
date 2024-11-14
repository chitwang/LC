typedef long long ll;
class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        map<ll, ll> mp;
        ll ans = 0;
        for(int i=0; i<nums.size();i++){
            ll cur = __gcd(nums[i], k);
            for(auto &m: mp){
                if((m.first * cur) % k == 0){
                    ans += m.second;
                }
            }
            mp[cur]++;
        }
        return ans;
    }
};