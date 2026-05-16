class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int>rows_containing_zeroes;//1
        vector<int>cols_containing_zeroes;//1

        for(int i = 0 ;i < rows ; i++)
        {
            for(int j = 0 ;  j < cols; j ++)
            {
                if(matrix[i][j] == 0)
                {
                    rows_containing_zeroes.push_back(i);//1
                    cols_containing_zeroes.push_back(j);//1
                }
            }
        }


        for(int i  = 0; i < rows_containing_zeroes.size() ; i++)
        {
            for(int j = 0 ; j< cols;j ++)
            {   
                matrix[rows_containing_zeroes[i]][j] = 0;
            }
        }

        for(int j =  0; j < cols_containing_zeroes.size(); j++)
        {
            for(int i = 0 ; i < rows;i ++)
            {
                matrix[i][cols_containing_zeroes[j]] = 0;
            }
        }   

        //TC : O(m*n)
        //SC : O(m+n)

    }
};