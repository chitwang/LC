class Solution {
public:
    vector<vector<int>> adj;
    vector<set<int>> guess_child;
    vector<int> par;
    int ans = 0;
    void dfs(int i, int p){
        par[i] = p;
        for(auto &it:adj[i]){
            if(it != p){
                dfs(it, i);
            }
        }
    }
    void dfs2(int i, int p, int guess, int k){
        if(guess >= k){
            ans++;
        }
        for(auto it:adj[i]){
            if(it == p)
                continue;
            int a1 = guess_child[i].count(it);
            int a2 = guess_child[it].count(i);
            if(a1 and a2){
                ;
            }
            else if(a1){
                guess--;
            }
            else if(a2){
                guess++;
            }
            dfs2(it, i, guess, k);
            if(a1 and !a2){
                guess++;
            }
            if(a2 and !a1){
                guess--;
            }
        }
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size() + 1;
        par.resize(n, -1);
        adj.resize(n);
        guess_child.resize(n);
        for(auto &ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        dfs(0, -1);
        int correct = 0;
        for(auto &g:guesses){
            guess_child[g[0]].insert(g[1]);
            if(par[g[1]] == g[0]){
                correct++;
            }
        }
        dfs2(0, -1, correct, k);
        return ans;
    }
};