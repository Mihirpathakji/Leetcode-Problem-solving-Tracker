class Solution {
public:


    int countIslands(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size(); 

        //BFS From a non_zero value.

        int counts = 0;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {

                long long island_sum = 0;

                if(grid[i][j]!=0) {
                    island_sum += grid[i][j];
                }
                else {
                    continue;
                }

                //store it's information in queue.To apply BFS.

                //store {i,j} in a queue.
                queue<pair<int,int>>q;
                q.push({i,j});

                vector<int>row_dir = {0,-1,0,1};
                vector<int>col_dir = {-1,0,1,0};
                //{0,1}

                while(!q.empty()) {

                    int r = q.front().first;
                    int c = q.front().second;

                    grid[r][c] = 0;

                    q.pop();


                    for(int i = 0;i < 4;i++) {
                        if((r + row_dir[i] < m  && r + row_dir[i] >=0 )&& (c+ col_dir[i] < n && c + col_dir[i] >=0 ) && grid[r+row_dir[i]][c+col_dir[i]] !=0 ) {
                            island_sum += grid[r+row_dir[i]][c+col_dir[i]];
                            q.push({r+row_dir[i],c+col_dir[i]});
                            grid[r+row_dir[i]][c+col_dir[i]] = 0;
                        }
                    }

                }

            
                if(island_sum%k == 0) {
                    counts++;
                }

            }

        }

        return counts;

    }
};