class Solution {
public:

    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int mod = 1e9+7;
        const int n = board.size();
        vector<vector<int>> paths(n+1, vector<int>(n+1,0));
        vector<vector<int>> score(n+1, vector<int>(n+1,0));
        paths[n-1][n-1] = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j] == 'S' or board[i][j] == 'X'){
                    continue;
                }
                if(max({paths[i][j+1], paths[i+1][j], paths[i+1][j+1]}) == 0)
                    continue;
                int pre = max({score[i+1][j], score[i][j+1], score[i+1][j+1]});
                // if(pre == -1)
                //     continue;
                if(board[i][j] == 'E')  
                    score[i][j] = pre;
                else
                    score[i][j] = pre + (board[i][j] - '0');
                if(pre == score[i+1][j]) paths[i][j] = (paths[i+1][j] + paths[i][j])%mod;;
                if(pre == score[i][j+1]) paths[i][j] = (paths[i][j+1] + paths[i][j])%mod;
                if(pre == score[i+1][j+1]) paths[i][j] = (paths[i+1][j+1] + paths[i][j])%mod;
            }
        }
        return {score[0][0], paths[0][0]};    
    }
};