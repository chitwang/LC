class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1] < b[1];
        });
        int ans = 0;
        vector<bool> mp(2005, false);
        int n = tasks.size();
        for(int i=0;i<n;i++){
            auto start = tasks[i][0];
            auto end = tasks[i][1];
            auto duration  = tasks[i][2];
            for(int j=end;j>=start;j--){
                if(mp[j]){
                    duration--;
                }
            }
            for(int j=end;j>=start and duration > 0;j--){
                if(!mp[j]){
                    mp[j] = true;;
                    duration--;
                }
            }
        }
        for(auto it:mp){
            ans += it;

        }
        return ans;
    }
};