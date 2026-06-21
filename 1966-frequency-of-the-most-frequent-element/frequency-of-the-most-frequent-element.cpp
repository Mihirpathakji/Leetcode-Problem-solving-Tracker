class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        int n = nums.size();

        long long i = 0;
        long long j = 0;//target index.We will try to make every element in nums equal to nums[j].Where we will take all possible j.

        sort(nums.begin(),nums.end());//->It gives the required Monotonicty 

        long long prefix_sum = 0;//It helps to compute the number of operations required to convert every element from i to jth into nums[j] in O(1) tC.

        long long max_freq = INT_MIN;

        while(j < n)
        {
            prefix_sum += nums[j];

            //Check if the Number of operations needed are in range of [0,k].

            long long operations_needed = (j-i+1)*(nums[j]) - prefix_sum;//prefixsum will contain subarray sum of subarray with length j-i+1 ,start = i and end = j.

            //If it exceeds the range.Than shrink the window Monotonically.

            //Dynamic size sliding window.

            while(operations_needed > k)
            {
                prefix_sum -= nums[i];
                i++;//We shrinked the window.
                
                //Now check that now if the operations needed become in range of [0,k].Calculating the new_operations needed.

                operations_needed = (j-i+1)*(nums[j]) - prefix_sum;//these are new operations after shrinking window.
            }


            max_freq = max(max_freq,j-i+1);//every element from i to j can be converted to nums[j]. 

            j++;

        }

        return max_freq;
        
    }
};