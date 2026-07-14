class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

       //Multisource BFS :

       int m = grid.size();
       int n = grid[0].size();

      vector<vector<bool>>visited(m,vector<bool>(n,false));
      int max_dist = 0;

     //filling the Queue with those things for which we have the exact same information. 

      queue<pair<pair<int,int>,int>>q;//{{i,j},distance}.

      for(int i = 0;i < m;i++) {
        for(int j = 0;j < n;j++) {

            //we have exact same information for all these types element.
            if(grid[i][j] == 1) {
                q.push( { { i , j } , 0 } );
                visited[i][j] = true;
            }
        }    
      }

    while(!q.empty()) {

        int row = q.front().first.first;
        int col = q.front().first.second;
        int curr_dist = q.front().second;
        q.pop();

        max_dist = max(max_dist,curr_dist);

        int row_dir[4] = {0,-1,0,1};
        int col_dir[4] = {-1,0,1,0};

        for(int i = 0;i < 4;i++) {
            if(row + row_dir[i] >= 0 &&  row + row_dir[i] < m && col + col_dir[i] >= 0 && col + col_dir[i] < n && visited[row + row_dir[i]][col + col_dir[i]] == false) {   

                visited[row + row_dir[i]][col + col_dir[i]] = true;
                q.push( { { row + row_dir[i] , col + col_dir[i] } , curr_dist + 1 } );
            }
        }
    }
     
        if(max_dist == 0) {
            return -1;//it is not possible that a water cell is at distance of 0 from a land cell.
        }

        return max_dist;

        //TC : O(m*n*4)
        //SC : O(m*n)

    }
};