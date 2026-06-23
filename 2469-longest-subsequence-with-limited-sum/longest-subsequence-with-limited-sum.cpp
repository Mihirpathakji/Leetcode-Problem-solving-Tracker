class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        int n  = nums.size();
        int m = queries.size();

        sort(nums.begin(),nums.end());//n*logn
        //since after sorting array we just need it's prefix sum, we can also do that in place.

        for(int i = 1; i < n; i++)
        {
            nums[i] = (nums[i] + nums[i-1]);
        }

        //For every Query i will binary search on the array nums.

        vector<int>ans;

        for(int i = 0; i  < m; i++)
        {
            int target = queries[i];//10 21 //1

            int low = 0;
            int high = n-1;//index.3
           
            bool flag = false;

            int possible_ans = 0;// If no elements in the array gave sum <= target.
         
            while(low <= high)
            {
                int mid = low + (high-low)/2;//1 2 3 //1 0

                if(nums[mid] == target)
                {
                    flag = true;
                    ans.push_back(mid+1);//
                    break;
                }
                else if(nums[mid] < target)
                {
                    low = mid +1;//3 // 
                    possible_ans = mid+1;//2 3 4 //
                }
                else
                {
                    high = mid -1;
                }

            }//logn  
           
            if(!flag)
            {
                ans.push_back(possible_ans);
            }
        
        }

        return ans;
   
        //TC : O(m*logn)
        //SC : O(1)
   
    }
};