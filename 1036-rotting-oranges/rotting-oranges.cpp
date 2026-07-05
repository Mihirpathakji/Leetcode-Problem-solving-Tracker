class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        //{{r,c},t}
        queue<pair<pair<int,int>,int>>q;//To track the time where the each fresh element was infected.

        //1.Initializing queue with all the rottens since they were rotten originally their rottening time is 0.

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                
                //pushing elements which were rotten initially.

                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
            }
        }

        //1.Doing bfs for all the rottens. 

        int max_time_at_which_any_one_infected = 0;

        //[row-1,col],[row,col-1],[row+1,col],[row,col+1].

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;

            int t = q.front().second;//cumulative time.
            q.pop();

            max_time_at_which_any_one_infected  = max(t,max_time_at_which_any_one_infected);

            int delrow[4] = {-1,0,1,0};
            int delcol[4] = {0,-1,0,1};

            for(int i = 0;i < 4;i++) {

                //if any fresh is in the neighbour than we need to convert it into the rotten.
                if(row + delrow[i] >=0 && row + delrow[i] < m && col + delcol[i] >=0 && col + delcol[i] < n && grid[row + delrow[i]][col + delcol[i]] == 1 ) {
                    
                    grid[row + delrow[i]][col + delcol[i]] = 2;
                    q.push({{row + delrow[i],col+delcol[i]},t+1});
                }
            }   

        }

        //If still any fresh orange remained in the grid after converting all possible fresh oranges into rotten one through bfs i.e not possible to cover that freshone.

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return max_time_at_which_any_one_infected;

        //TC : O(m*n*4)
        //SC : O(m*n)


    }
};