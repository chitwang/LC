class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
    long long hash = 0, res = 0, power_k = 1;
    auto val = [&](int i){ return s[i] - '`'; };
    for (int i = s.size() - 1; i >= 0; --i) {
        hash = (hash * power + val(i)) % mod;
        if (i < s.size() - k)
            hash = (mod + hash - power_k * val(i + k) % mod) % mod;
        else
            power_k = power_k * power % mod;
        if (hash == hashValue)
            res = i;        
    }
    return s.substr(res, k);
}
};