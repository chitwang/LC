typedef long long ll;
class SG_lazy{
    public:
    ll n;
    vector<ll> seg;
    vector<ll> lazy;
    SG_lazy(vector<int>&arr){
        this->n = arr.size();
        this->seg.resize(4*this->n);
        this->lazy.resize(4*this->n);
    }
    void build(int ind, int low, int high, vector<int>&arr){
        if(low == high){
            this->seg[ind] = arr[low];
            return;
        }
        int mid = (low + high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);
        this->seg[ind] = (this->seg[2*ind+1] + this->seg[2*ind+2]);
    }

    ll query(int ind, int low, int high, int l, int r){
        if(r < low || high < l){
            return 0;
        }
        if(low >= l and high <= r){
            return this->seg[ind];
        }
        int mid = (low + high) >> 1;
        ll a1 = query(2*ind+1, low, mid, l, r);
        ll a2 = query(2*ind+2, mid+1, high, l, r);
        return min(a1, a2);
    }

    void point_update(int ind, int low, int high, int val, int i){
        if(low == high){
            this->seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if(i <= mid){
            point_update(2*ind+1, low, mid, val, i);
        }
        else{
            point_update(2*ind+2, mid+1, high, val, i);
        }
        this->seg[ind] = min(this->seg[2*ind+1], this->seg[2*ind+2]);
    }

    void range_update(int ind, int low, int high, int l, int r){
        if(this->lazy[ind]){
            this->seg[ind] = (high - low + 1) - this->seg[ind];
            if(low != high){
                this->lazy[2*ind+1] ^= 1; 
                this->lazy[2*ind+2] ^= 1; 
            }
            this->lazy[ind] = 0;
        }
        if(high < l or low > r){
            return;
        }
        if(low >= l and high <= r){
            this->seg[ind] = (high - low + 1) - this->seg[ind];
            if(low != high){
                this->lazy[2*ind + 1] ^= 1;
                this->lazy[2*ind + 2] ^= 1;
            }
            return;
        }
        int mid = (low + high) >> 1;
        range_update(2*ind+1, low, mid, l, r);
        range_update(2*ind+2, mid+1, high, l, r);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }

    ll range_query(int ind, int low, int high, int l, int r){
       if(this->lazy[ind]){
            this->seg[ind] = (high - low + 1) - this->seg[ind];
            if(low != high){
                this->lazy[2*ind+1] ^= 1; 
                this->lazy[2*ind+2] ^= 1; 
            }
            this->lazy[ind] = 0;
        }
        if(r < low || high < l){
            return 0;
        }
        if(low >= l and high <= r){
            return this->seg[ind];
        }
        int mid = (low + high) >> 1;
        ll a1 = query(2*ind+1, low, mid, l, r);
        ll a2 = query(2*ind+2, mid+1, high, l, r);
        return a1 + a2;
    }

};


class Solution {
public:
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> ans;
        long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
        SG_lazy seg(nums1);
        seg.build(0, 0, nums1.size()-1, nums1);
        for(auto &q:queries){
            if(q.front() == 2){
                long long p = q[1];
                p *= seg.range_query(0, 0, nums1.size()-1, 0, nums1.size()-1);
                sum += p;
            }
            else if(q.front() == 3){
                ans.push_back(sum);
            }
            else{
                seg.range_update(0, 0, nums1.size()-1, q[1], q[2]);
            }
        }
        return ans;
    }
};