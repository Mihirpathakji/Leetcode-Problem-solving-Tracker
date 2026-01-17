class Solution {
public:
    int longestMountain(vector<int>& arr) {
       
       int n=arr.size();//z
       int ans = 0;
        
        for(int i=1;i<n-1;i++)
        {   
            int j;
            
            if( arr[i-1] < arr[i]  && arr[i] > arr[i+1] )
            {
                j=i;//3
                int left_len=0;

                while(j)
                {
                    j--;//2 1 0
                    if( j< n-1 && arr[j] < arr[j+1])
                    {
                        left_len++;//1 2
                    }
                    else
                    {
                        break;
                    }
                }
                
                int j1=i;//3
                int right_len=0;
                while(j1 < n-1)
                {//
                    if(arr[j1] > arr[j1+1])
                    {
                        right_len++;//1 2 
                    }
                    else
                    {
                        break;
                    }
                    j1++;//4 5
                }
                ans = max(ans,( left_len + right_len + 1));
            }
        }
        return ans;

        //TC:O(n^2)
        //SC:O(1)

    }
};