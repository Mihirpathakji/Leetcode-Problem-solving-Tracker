class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        int n  = nums.size();
        int n1 = queries.size();

        sort(nums.begin(),nums.end());
        vector<int>prefix_sum(n);
        prefix_sum[0] = nums[0];

        for(int i = 1; i < n; i++)
        {
            prefix_sum[i] = prefix_sum[i-1] + nums[i]; 
        }


        //For every Query i will binary search on the array nums.

        vector<int>ans;

        for(int i = 0; i  < n1; i++)
        {
            int target = queries[i];//10

            int low = 0;
            int high = n-1;
           
            bool flag = false;

            int possible_ans = 0; 
         
            while(low <= high)
            {
                int mid = low + (high-low)/2;//1 2

                if(prefix_sum[mid] == target)
                {
                    flag = true;
                    ans.push_back(mid+1);//2
                    break;
                }
                else if(prefix_sum[mid] < target)
                {
                    low = mid +1;
                    possible_ans = mid+1;
                }
                else
                {
                    high = mid -1;
                }
            }   
            if(!flag)
            {
                ans.push_back(possible_ans);
            }
        }

        return ans;
    }
};