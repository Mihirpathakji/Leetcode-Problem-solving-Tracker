class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n  = grid.size();
        int min_swaps = 0;
        
        vector<int>trailing_zeroes(n);
        vector<int>need(n);

        //need computation;
        for(int i=0; i<n;i++)
        {
            need[i] = n-i-1;
        }

        //trailing_zeroes computation: computing Number of zeroes in continuous fashion from back
        for(int i=0;i<n;i++)
        {
            int zeroes_from_back = 0;//0
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j] == 0)
                {
                    zeroes_from_back++;
                    if(j == n-1)
                    {
                        trailing_zeroes[i] = zeroes_from_back;
                    }
                }
                else
                {
                    trailing_zeroes[i] = zeroes_from_back;
                    break;
                }
            }
        }

        for(int i=0;i<trailing_zeroes.size();i++)
        {
            if(trailing_zeroes[i] < need[i])
            {//there is need to swap
                bool flag = false;
                for(int j = i+1;j<trailing_zeroes.size();j++)
                {
                    if(trailing_zeroes[j] >= need[i])
                    {
                        flag = true;
                        min_swaps += j-i;
                        //Bubble that trailing_zeroes[j] to trailing_zeroes[i] by adjacent swaps.

                        while(j > i)
                        {
                            swap(trailing_zeroes[j],trailing_zeroes[j-1]);
                            j--;
                        }
                        //For that i job is done .Now trailing_zeroes[i] >= need[i] no need to anything for that ith row now.
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
        //TC:O(n^2)
        //SC:O(n)
    }
};