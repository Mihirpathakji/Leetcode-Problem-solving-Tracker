class Solution {
public:

    int maxMoves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        //Initializing q with starting points.

        int j = 0;
        for(int i = 0;i < m;i++) {
            q.push({i,j});
            visited[i][j] = true;
        }

        int total_levels = 0;
        int max_optimal_moves = 0;

        while(!q.empty()) {

            int n1 = q.size();//4 

            while(n1--) {
                //n = 2

                int row = q.front().first;//0 1 2
                int col = q.front().second;//0 0 0 
                max_optimal_moves = max(max_optimal_moves,col);
                q.pop();//

                int row_dir[] = {-1,0,1};
                int col_dir[] = {1,1,1};

                for(int i = 0;i < 3;i++) {
                    if(row + row_dir[i] >= 0 && row + row_dir[i] < m && col + col_dir[i] >= 0 && col + col_dir[i] < n && visited[row + row_dir[i]][col + col_dir[i]] == false && grid[row + row_dir[i]][col + col_dir[i]] > grid[row][col]) {
                        
                        q.push({row + row_dir[i],col + col_dir[i]});
                        visited[row + row_dir[i]][col + col_dir[i]] = true;
                    }   
                }       

            }
            
        }

        return max_optimal_moves;

        //TC : O(m*n*3)
        //SC : O(m*n)    

    }
};