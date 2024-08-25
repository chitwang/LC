class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size();
        unordered_map<int, int> mp;
        int ans = 0;
        int cur = 0;
        for(auto it:rolls){
            mp[it]++;
            if(mp[it] == 1){
                cur++;
            }
            if(cur == k){
                cur = 0;
                mp.clear();
                ans++;
            }
        }
        return ++ans;
    }
};