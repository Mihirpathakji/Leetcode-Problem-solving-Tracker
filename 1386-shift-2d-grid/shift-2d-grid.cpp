class Solution {
public:
    
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>temp(m,vector<int>(n));
        int total_index = (m-1)*n + n;

        for(int i = 0;i < m;i++) {
            for(int j = 0;j < n;j++) {

                int curr_row = i;//0 0 0 1 1 1
                int curr_col = j;//0 1 2 0 1 2
 
                int index_in_1d = (curr_row * n) + curr_col;//0 1 2 3 4 5

                int new_index_in_1d = (index_in_1d + k) % total_index;//1 2 4 5 6

                int new_row = (new_index_in_1d / n);//0 0 1 1
                int new_col = new_index_in_1d % n;//1 2 1 2 

                temp[new_row][new_col] = grid[curr_row][curr_col];// 

            }
        }

        return temp;//  

        //TC : O(m*n) 
        //SC : O(m*n)
        
    }
};