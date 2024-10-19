// typedef long long ll;

// class Solution {
// public:
//     bool foo(vector<int> &stations, int r, int k, ll p){
//         int left = 0;
//         int right = r;
//         size_t n = stations.size();
//         ll curp = 0;
//         for(int i=0;i<=r;i++) curp += stations[i];
//         for(int i=0;i<n;i++){
//             if(i - left > r){
//                 curp -= stations[left++];
//             }
//             if(right-i < r and right < n-1){
//                 curp += stations[++right];
//             }
//             if(curp < p){
//                 if(k < p - curp) return false;
//                 stations[right] += p - curp;
//                 k -= p-curp;
//                 curp = p;
//             }
//         }
//         return true;
//     }
//     long long maxPower(vector<int>& stations, int r, int k) {
//         ll l = 0;
//         ll ri = 1e18;
//         ll ans = 0;
//         while(l <= ri){
//             ll mid = (l + ri) >> 1;
//             if(foo(stations, r, k, mid)){
//                 l = mid + 1;
//                 ans = mid;
//             }
//             else{
//                 ri  = mid - 1;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long right = LLONG_MAX, left = 0;
        long long best = 0;
        
        while(left<=right){
            long long mid = left+(right-left)/2;
            if(isPossible(mid,stations,r,k)){
                best = mid;
                left = mid+1;
            }else{
                right = mid - 1;
            }
        }
        return best;
    }
    


    bool isPossible(long long min_power, vector<int> stations, int r, int k){
        long long cur_power = 0,power_needed=0;
        int n = stations.size();
        for (int i = 0; i <= r; i++) cur_power += stations[i];

        int left = 0, right = r;
        for (int i = 0; i < n; i++){
            if (i-left>r){
                cur_power -= stations[left];
                left ++;
            }
            if (right-i<r and right<n-1){
                right ++;
                cur_power += stations[right];
            }

            if (cur_power < min_power){
                power_needed = min_power-cur_power;
                if (k<power_needed) return false;
                stations[right] += power_needed;
                cur_power += power_needed;
                k -= power_needed;
            }
        }
        return true;
    }
};