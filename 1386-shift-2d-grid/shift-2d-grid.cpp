class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>temp(m,vector<int>(n));

        temp = grid; 

        for(int i = 0;i < k; i++) {

            //1.i = 0.
            
            for(int l = 0;l < m; l++) {
                for(int j = 0;j < n-1;j++) {
                    temp[l][j+1] = grid[l][j];//temp[0][0] = grid[0][1]  .This grid should not be the original one it should be the one that accumulates the changed grid values.
                }
            }

            for(int l = 0;l < m-1; l++) {
                for(int j = n-1;j < n;j++) {
                    temp[l+1][0] = grid[l][j];
                }
            } 

            temp[0][0] = grid[m-1][n-1];// 9.    
            
            grid = temp;//changed the grid to accumulate the changes done it.

        }

        return grid;
        
    }
};