class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

        //DFS way remaining.

        int counts = 0;

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>visited(m,vector<int>(n,-1));

        int row_dir[4] = {0,-1,0,1};
        int col_dir[4] = {-1,0,1,0};

        for(int j = 0;j < n;j++) {
            if(grid[0][j] == 0) {
                q.push({0,j});
                visited[0][j] = 1;
            }
            if(grid[m-1][j] == 0) {
                q.push({m-1,j});
                visited[m-1][j] = 1;
            }
        }

        for(int i = 0;i < m;i++) {
            if(grid[i][0] == 0) {
                q.push({i,0}); 
                visited[i][0] = 1;
            }

            if(grid[i][n-1] == 0) {
                q.push({i,n-1});
                visited[i][n-1] = 1;
            }
        }

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();


            for(int i = 0;i < 4;i++) {
                if(row + row_dir[i] >=0 && row + row_dir[i] < m && col+ col_dir[i] >= 0 && col + col_dir[i] < n && visited[row+row_dir[i]][col+col_dir[i]] == -1){   
                    if(grid[row + row_dir[i]][col + col_dir[i]] == 0) {
                        visited[row+row_dir[i]][col + col_dir[i]] = 1;//this is boundary island.
                        q.push({row+row_dir[i],col+col_dir[i]});
                    }
                }
            }

        }

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                
                if((visited[i][j] ==-1) && grid[i][j] == 0) {

                    q.push({i,j});
                    visited[i][j] = 1;
                    counts++;

                    while(!q.empty()) {

                        int row = q.front().first;
                        int col = q.front().second;

                        q.pop();

                        for(int k = 0; k < 4;k++) {
                            if((row + row_dir[k] > 0) && (row + row_dir[k] < m-1) && (col + col_dir[k] >0 ) && (col + col_dir[k] < n-1) && (visited[row+row_dir[k]][col+col_dir[k]] == -1)) {
                                if(grid[row+row_dir[k]][col+col_dir[k]]==0) {
                                    q.push({row+row_dir[k],col+ col_dir[k]});
                                    visited[row+row_dir[k]][col+col_dir[k]] = 1;
                                }
                            }
                        }

                    }

                }

            }
        }

        return counts;

        //TC : O(m*n*8)
        //SC : O(m*n)
        
    }
};