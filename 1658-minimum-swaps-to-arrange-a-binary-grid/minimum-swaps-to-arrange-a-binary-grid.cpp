class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int>need(n);
        int min_swaps = 0;

        for(int row = 0; row < n; row++)
        {
            need[row] = n - row  -1;
        }

        vector<int>trailing_zeroes(n);

        for(int row = 0; row < n; row ++)
        {  
            int trailing_zeroes_cnt = 0;
            for(int j = n -1; j >=0 ; j--)
            {
                if(grid[row][j] == 0)
                {
                    trailing_zeroes_cnt++;
                    if(j == 0)
                    {
                        trailing_zeroes[row] = trailing_zeroes_cnt;
                    }
                }   
                else
                {
                    trailing_zeroes[row] = trailing_zeroes_cnt;
                    break;
                }
            }
        }

        for(int  i = 0; i < trailing_zeroes.size(); i ++)
        {
            bool flag = false;
            if(trailing_zeroes[i] < need[i])
            {
                for(int j = i+1 ; j < trailing_zeroes.size() ; j++)
                {
                    
                    if(trailing_zeroes[j] >= need[i])
                    {
                        flag = true;
                        min_swaps += j-i;
                        while(j > i){
                            swap(trailing_zeroes[j],trailing_zeroes[j-1]);
                            j--;
                        }   
                        break;
                    }
                }
                if(flag == false)
                {
                    return -1;
                }
             
            }
        }

        return min_swaps;
        
    }
};