


class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<vector<int>>> adj(n);
        for(auto &met:meetings){
            adj[met[0]].push_back({met[1], met[2]});
            adj[met[1]].push_back({met[0], met[2]});
        }
        vector<int> dis(n, 1e9);
        dis[0] = 0;
        dis[firstPerson] = 0;
        queue<int> q;
        q.push(0);
        q.push(firstPerson);
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            for(auto &it:adj[x]){
                if(it[1] >= dis[x] and it[1] < dis[it[0]]){
                    q.push(it[0]);
                    dis[it[0]] = it[1];
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(dis[i] != 1e9){
                ans.push_back(i);
            }
        }
        return ans;
    }
};