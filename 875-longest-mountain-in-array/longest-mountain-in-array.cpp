class Solution {
public:
    int longestMountain(vector<int>& arr) {
       
       int n=arr.size();
       int ans = 0;
        
        for(int i=1;i<n-1;i++)
        {   
            int j;
            
            if( arr[i-1] < arr[i]  && arr[i] > arr[i+1] )
            {
                j=i;
                int left_len=0;

                while(j)
                {
                    j--;
                    if( j< n-1 && arr[j] < arr[j+1])
                    {
                        left_len++;
                    }
                    else
                    {
                        break;
                    }
                }
                
                int j1=i;
                int right_len=0;
                while(j1 < n-1)
                {
                    if(arr[j1] > arr[j1+1])
                    {
                        right_len++;
                    }
                    else
                    {
                        break;
                    }
                    j1++;
                }
                ans = max(ans,( left_len + right_len + 1));
            }
        }
        return ans;

        //TC:O(n^2)
        //SC:O(1)

    }
};