class Solution {
public:

    void mybfs(int i,int j,queue<pair<int,int>>& q,vector<vector<bool>>& visited,vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        visited[i][j] = true;
        q.push({i,j});

        while(!q.empty()) {
            
            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            //Check all it's neighbours :

            for(int l = -1;l <= 1;l++) {
                for(int r = -1;r <= 1;r++) {
                    if(abs(l*r)!=1) {

                        if(row+l >=0 && row+l <m && col+r >=0 && col+r<n && grid[row+l][col+r] == '1' && visited[row+l][col+r] == false) {

                            q.push({row+l,col+r});
                            visited[row+l][col+r] = true;
                        }
                    }
                }
            }

            //{-1,0},{1,0},{0,1},{0,-1}
            //nope : {-1,-1},{-1,1},{1,-1},{1,1} ->abs(mul)!=1

        }

    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        int bfs_counts = 0;
        queue<pair<int,int>>q;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(visited[i][j] == false  && grid[i][j] == '1') {
                    bfs_counts++;
                    mybfs(i,j,q,visited,grid);
                }
            }
        }
        
        return bfs_counts;
        
        //TC : O(m*n) + O(4*m*n)

        //SC : O(m*n)
    }
};