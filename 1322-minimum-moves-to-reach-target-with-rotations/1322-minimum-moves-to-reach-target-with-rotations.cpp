struct snake{
    int x1, y1,  x2,  y2;
    snake(int x1, int y1, int x2, int y2){
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    bool operator<(const snake& other) const {
        if (x1 != other.x1) return x1 < other.x1;
        if (y1 != other.y1) return y1 < other.y1;
        if (x2 != other.x2) return x2 < other.x2;
        return y2 < other.y2;
    }
};

class Solution {
public:
    // x2, y2 where mouth is
    vector<snake> get_moves(vector<vector<int>> &grid, snake &sn){
        int n = grid.size();
        vector<snake> ans;
        int y2 = sn.y2;
        int y1 = sn.y1, x1=  sn.x1, x2 = sn.x2;
        if(sn.x1 == sn.x2){
            if(y2 + 1 < n and grid[x1][y2+1] == 0){
                ans.push_back(snake(x2, y2, x2, y2+1));
            }
            if(x1 + 1 < n and grid[x1+1][y1] == 0 and grid[x1+1][y2] == 0){
                ans.push_back(snake(x1, y1, x1+1, y1));
                ans.push_back(snake(x1+1, y1, x2+1, y2));
            }

        }  
        else if(sn.y1 == sn.y2){
            if(x2 + 1 < n and grid[x2+1][y2] == 0){
                ans.push_back(snake(x2, y2, x2+1, y2));
            }
            if(y1 + 1 < n and grid[x1][y1+1] == 0 and grid[x2][y1+1] == 0){
                ans.push_back(snake(x1, y1, x1, y1+1));
                ans.push_back(snake(x1, y1+1, x2, y1+1));
            }
        } 
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid)
    {
        int n = grid.size();
        queue<snake> q;
        map<snake, int> mp;
        snake sn(0,0,0,1);
        q.push(sn);
        mp[sn] = 0;
        while(!q.empty()){
            auto x = q.front();
            // cout << x.x1 << " " << x.y1 << " " << x.x2 << " " << x.y2 << endl;
            q.pop();
            vector<snake> mvs = get_moves(grid, x);
            for(auto it:mvs){
                if(!mp.count(it)){
                    q.push(it);
                    mp[it] = mp[x] + 1;
                }
            }
        }
        snake fina(n-1, n-2, n-1, n-1);
        return mp.count(fina) ? mp[fina] : -1;
    }
};