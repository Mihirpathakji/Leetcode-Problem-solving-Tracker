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
                if(grid[i][j] == 1 && i!=0 && i!=m-1 && j!=0 && j!=n-1) {
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1 && (i ==0 || i == m-1 || j==0 || j == n-1)) {
                    q.push({i,j});
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
                
                if(row + row_dir[i] >= 0 && row + row_dir[i]  < m && col + col_dir[i] >= 0 && col + col_dir[i] < n && visited[row + row_dir[i]][col + col_dir[i]] == true) {
                    //i.e are not visited and are bottomed->true.

                    visited[row+row_dir[i]][col+col_dir[i]] = false;
                    q.push({row + row_dir[i] ,col + col_dir[i]});
                }
            }
        }

        int ans = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(visited[i][j] == true) {
                    ans++;
                }
            }
        }

        return ans;

        
    }
};