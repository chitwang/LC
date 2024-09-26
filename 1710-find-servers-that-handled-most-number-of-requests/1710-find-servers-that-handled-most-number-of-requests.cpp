class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> server(k, 0);
        int n = arrival.size();
        set<int> free_server;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0;i<k;i++){
            free_server.insert(i);
        }
        for(int i=0;i<n;i++){
            while(!pq.empty() and pq.top().first <= arrival[i]){
                free_server.insert(pq.top().second);
                pq.pop();
            }
            if(free_server.empty()){
                continue;
            }
            auto it = free_server.lower_bound(i%k);
            if(it == free_server.end()){
                it = free_server.begin();
            }
            server[*it]++;
            pq.push({arrival[i]+load[i], *it});
            free_server.erase(*it);
            
        }
        vector<int> ans;
        int maxi = *max_element(server.begin(), server.end());
        for(int i=0;i<k;i++){
            if(server[i] == maxi){
                ans.push_back(i);
            }
        }
        return ans ;
    }
};