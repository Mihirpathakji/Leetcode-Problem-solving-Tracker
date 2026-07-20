class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>ans(m,vector<int>(n));

        //shifting 2d matrix is same as shifting 1d array.

        int total_cols = n;
        int total_index = m*n;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {

                int curr_row = i;
                int curr_col = j;

                int index_in_1d = (curr_row * total_cols) + curr_col;

                //shifted the 1d array by k places.

                int new_index_in_1d = ( index_in_1d + k ) % total_index;      

                //Converting 1d to New 2d matrix again :        

                int new_row = new_index_in_1d / total_cols;
                int new_col = new_index_in_1d % total_cols;

                ans[new_row][new_col] = grid[curr_row][curr_col];

            }
        }

        return ans;
        
        //TC : O(m*n)
        //SC : O(m*n)

        
    }
};