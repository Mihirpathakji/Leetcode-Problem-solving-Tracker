class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int n = nums.size();
        int max_Difference = -1;
        int Suffix_Max = -1;

        for(int i = n - 2 ; i >= 0 ; i-- )
        {//
            Suffix_Max = max(Suffix_Max,nums[i+1]);//15 23 26 

            if(Suffix_Max - nums[i] != 0)
            {
                max_Difference = max(max_Difference,Suffix_Max-nums[i]);//-1,0 
            }
        }

        return max_Difference;

        //TC : O(n)
        //SC : O(1)
    }
};