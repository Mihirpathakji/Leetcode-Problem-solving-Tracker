class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        //{{r,c},t}

        queue<pair<pair<int,int>,int>>q;//We will store the address of all the rotten oranges and the time where each rotten orange started it's bfs.


        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        //When we do BFS, Than at end the maximum time taken by any rottened is the ans.

        for(int i = 0;i< m; i++) {
            for(int j = 0;j < n;j++) {

                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
            }
        }
        int mxtime = 0;

        //Applying BFS to cover all fresh oranges.

        //{row-1,col},{row+1,col},{row,col-1},{row,col+1}
        
        int delrow[4] = {-1,1,0,0};
        int delcol[4] = {0,0,-1,1};

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            mxtime = max(t,mxtime);  

            q.pop();

            //Check all it's Neighbours.

            for(int i = 0;i <4;i++) { 
                if(row + delrow[i] >=0 && row + delrow[i] < m && col + delcol[i] >=0  && col + delcol[i] < n && grid[row+delrow[i]][col+delcol[i]] == 1 && visited[row+delrow[i]][col+delcol[i]] !=2) {

                    visited[row+delrow[i]][col+delcol[i]] = 2;
                    q.push({{row+delrow[i],col+delcol[i]},t+1});
                }
            }
        }

        //If any fresh orange is remaining to be rottened.

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1 && visited[i][j]!=2) 
                {   
                    return -1;
                }
            }
        }

        return mxtime;

        //TC : O(m*n) + O(m*n*4)
        //SC : O(m*n)
        
    }
};