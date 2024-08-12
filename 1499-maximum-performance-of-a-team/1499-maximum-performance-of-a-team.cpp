class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(), v.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        long long cur = 0;
        const int mod = 1e9+7;
        for(int i=0;i<n;i++){
            pq.push(v[i].second);
            cur += v[i].second;
            if(pq.size() <= k){
                ans = max(ans, (cur * v[i].first));
                if(pq.size() == k){
                    cur -= pq.top();
                    pq.pop();
                }
            }
        }
        return ans%mod;
    }
};