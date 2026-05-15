class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<pair<int,int>>v;
        
        for(int i = 0 ;i < rows ; i++)
        {
            for(int j = 0 ; j < cols; j ++)
            {
                if(matrix[i][j] == 0)
                {
                    v.push_back({i,j});
                }
            }
        }
        
        for(int k = 0 ; k < v.size(); k++)
        {
            //v[k] = {i,j}; // [1,2] ,[3,4]
           
            for(int column = 0 ; column < cols ; column++)
            {
                matrix[v[k].first][column] = 0;
            }

            for(int row = 0; row < rows ; row++)
            {
                matrix[row][v[k].second] = 0;
            }
        }

    }
};