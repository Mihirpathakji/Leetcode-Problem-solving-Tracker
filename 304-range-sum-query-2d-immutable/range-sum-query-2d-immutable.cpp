class NumMatrix {
public:

// Make a global vector. 

    vector<vector<int>>prefix_matrix;

    NumMatrix(vector<vector<int>>& matrix) {

        //Compute the Prefix_Matrix:-> - topleft.

        int m = matrix.size();//rows.
        int n = matrix[0].size();//cols.

        prefix_matrix = vector<vector<int>>(m,vector<int>(n));

        for(int i = 0; i < m ;i++)
        {
            for(int j = 0;j < n;j++)
            {
                int top = (i>0) ? prefix_matrix[i-1][j] : 0;
                int left = (j>0) ? prefix_matrix[i][j-1] : 0;
                int topleft = (i>0 && j>0) ? prefix_matrix[i-1][j-1] : 0;   

                prefix_matrix[i][j] = matrix[i][j] + top + left - topleft;
            }
        }
        
        //O(m*n)

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        //answering Queries: -> + topleft.
        //+topleft

        //tc : O(1).

        int total = prefix_matrix[row2][col2];
        int top  = (row1 > 0) ? prefix_matrix[row1-1][col2] : 0;
        int left = (col1 > 0) ? prefix_matrix[row2][col1-1] : 0;
        int topleft = (row1>0 && col1>0) ? prefix_matrix[row1-1][col1-1] : 0;  

        //after all q queries tc : O(q*1)).

        return total - left - top + topleft;
    }

    //tc : O(m*n + q)
    //sc : O(m*n)

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */