class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[grid[i][j]]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans.size()==1)
            {
                break;
            }
            for(int j=0;j<n;j++)
            {  
                if(mp[grid[i][j]]>1)
                {
                    ans.push_back(grid[i][j]);
                    break;
                }
            }
        }
        //->Is there any element between 1 to n*n which is not yet mapped by the mp??
        for(int i=1;i<=n*n;i++)
        {
            if(!mp[i])
            {
                ans.push_back(i);
                break;
            }
        }      return ans;

        //TC:O(n^2)
        //SC:O(n^2)
    }
};