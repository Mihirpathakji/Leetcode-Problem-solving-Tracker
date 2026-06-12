class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int>prefix_xor(arr.size());

        prefix_xor[0] = arr[0];

        for(int i = 1;i < arr.size(); i++)
        {   
            prefix_xor[i] = arr[i]^prefix_xor[i-1];
        }

        vector<int>ans(queries.size());
        for(int i = 0;i < queries.size(); i++)
        {   
            if(queries[i][0] == 0 )
            {
                ans[i] = prefix_xor[queries[i][1]];
            }
            else
            {
                ans[i] = prefix_xor[queries[i][1]] ^ prefix_xor[queries[i][0]-1];
            }
        }

        return ans;
        
        //TC : O(3*10^4) 
        //SC : O(arr.size())
                
    }
};