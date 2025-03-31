//TC(O(10 * 10 * num.size()))
class Solution {
public:
    using ll = long long;
    
    vector<int> splitIntoFibonacci(string num) {
        int n = num.size();
        vector<int> res;
        for(int i = 1; i <= 10 && i <= n - 2; i++){   //becase n1 < pow(2, 31), i <= 10;
            string s1 = num.substr(0, i);
            ll n1 = stoll(s1);
            if((i > 1 && s1[0] == '0') || (n1 >= pow(2, 31))) continue;
            res.push_back(n1);
            for(int j = 1; j <= 10 && i + j <= n - 1; j++){
                string s2 = num.substr(i, j);
                ll n2 = stoll(s2);
                if((j > 1 && s2[0] == '0') || (n2 >= pow(2, 31))) continue;
                res.push_back(n2);
                if(dfs(n1, n2, i + j, num, res)) return res;
                res.pop_back();
            }
            res.clear();
        }
        return res;
    }

    bool dfs(ll n1, ll n2, int i, const string& num, vector<int>& res){
        int n = num.size();
        if(i == n) return true;
        if(n1 + n2 >= pow(2, 31)) return false;
        ll n3 = n1 + n2;
        string str = to_string(n3);
        int m = str.size();
        if(i + m > n) return false;
        if(num.substr(i, m) != str) return false;
        res.push_back(n3);
        if(dfs(n2, n3, i + m, num, res)) return true;
        res.pop_back();
        return false;
    }
};