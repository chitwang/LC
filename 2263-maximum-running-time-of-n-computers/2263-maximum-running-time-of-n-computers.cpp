typedef long long ll;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        ll low = 1;
        ll high = accumulate(batteries.begin(), batteries.end(), 0LL)/n;
        ll ans = 1;
        while(low <= high)
        {
            ll mid = (low+high)/2;
            ll t = 0;
            for(auto b:batteries) {
                t += min(ll(b), mid);
            }
            if(mid *n <= t) {low = mid+1; ans = mid;}
            else high = mid-1;

        }
        return ans;
    }
};