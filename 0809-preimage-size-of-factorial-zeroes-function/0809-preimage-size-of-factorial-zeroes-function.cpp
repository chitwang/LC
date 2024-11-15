class Solution {
public:
    long long int f(long long int n){
        long long int ans = 0;
        long long int p = 5;
        while(1){
            if(n/p == 0){
                break;
            }
            ans += n/p;
            p *= 5;
        }
        return ans;
    }
    int preimageSizeFZF(int k) {
        long long int low = 0;
        long long int high = 1e14;
        long int a = 0;
        long long int b = 0;
        while(low <= high){
            long long int mid = (low + high) >> 1;
            if(f(mid) >= k){
                high = mid - 1;
                a = mid;
            }
            else{
                low = mid + 1;
            }
        }
        low = 0;
        high = 1e14;
        while(low <= high){
            long long int mid = (low + high) >> 1;
            if(f(mid) >= k+1){
                high = mid - 1;
                b = mid;
            }
            else{
                low = mid + 1;
            }
        }
        cout << a << " " << b << endl;
        return b - a;
    }
};