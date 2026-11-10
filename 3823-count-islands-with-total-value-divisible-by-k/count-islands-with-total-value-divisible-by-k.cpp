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

                //Perform BFS from this Non zero valued island.

                if(grid[i][j]!=0) {
                    island_sum += grid[i][j];
                }
                else {
                    continue;
                }

                //store it's information in queue.To apply BFS.

                //store {i,j} in a queue.

                //To perform BFS in a grid . We need the information about the row and the coulumn number.

                queue<pair<int,int>>q;//{row,col}.
                q.push({i,j});

                vector<int>row_dir = {0,-1,0,1};//New_updations to the row number.
                vector<int>col_dir = {-1,0,1,0};//New_updations to the col number.
                //{0,1}

                while(!q.empty()) {

                    int r = q.front().first;
                    int c = q.front().second;

                    grid[r][c] = 0;//Mark it visited because while performing BFS. We should not revisit any visited node.

                    q.pop();

                    for(int i = 0;i < 4;i++) {
                        if((r + row_dir[i] < m  && r + row_dir[i] >=0 )&& (c+ col_dir[i] < n && c + col_dir[i] >=0 ) && grid[r+row_dir[i]][c+col_dir[i]] !=0 ) {
                            island_sum += grid[r+row_dir[i]][c+col_dir[i]];
                            q.push({r+row_dir[i],c+col_dir[i]});
                            //To perform BFS from that node.
                            grid[r+row_dir[i]][c+col_dir[i]] = 0;
                            //marked it as visited.
                        }
                    }

                    //match=> update count => queue for BFS => done.

                }

            
                if(island_sum%k == 0) {
                    counts++;
                }

            }

        }

        return counts;

    }
};