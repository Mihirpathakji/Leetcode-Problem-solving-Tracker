class Solution {
public:
    vector<string> createGrid(int m, int n) {

        vector<string>ans(m);
        
        for(int i =0; i<m; i++)
        {
            if(i == 0)
            {
                //0th row.fill up all withs .
                for(int j=0;j<n;j++)
                {
                    ans[i].push_back('.');
                }
            }
            else
            {
                for(int j = 0; j <n;j++)
                {
                    if(j == n-1)
                    {
                        ans[i].push_back('.');
                    }
                    else
                    {
                        ans[i].push_back('#');
                    }
                }
            }
        }

        return ans;

    }
};