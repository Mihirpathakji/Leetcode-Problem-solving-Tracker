class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        //We will mark all the ones on the boundary as false and push them into the q.They will went and reach all possible ones from them and marks those as F ans will be number of trues.

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1 && (i ==0 || i == m-1 || j==0 || j == n-1)) {
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }

        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int row_dir[4] = {0,-1,0,1};
            int col_dir[4] = {-1,0,1,0};

            for(int i = 0;i < 4;i++) {
                
                if(row + row_dir[i] >= 0 && row + row_dir[i]  < m && col + col_dir[i] >= 0 && col + col_dir[i] < n && visited[row + row_dir[i]][col + col_dir[i]] == false && grid[row+row_dir[i]][col + col_dir[i]] == 1) {
                    //i.e are not visited and are bottomed->true.

                    visited[row + row_dir[i]][col + col_dir[i]] = true;
                    q.push({row + row_dir[i] ,col + col_dir[i]});
                }
            }
        }

        int ans = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1 && visited[i][j] == false) {
                    ans++;//1 2 3 
                }
            }
        }

        return ans;

        //TC : O(m*n*4)
        //SC : O(m*n)
        
    }
};