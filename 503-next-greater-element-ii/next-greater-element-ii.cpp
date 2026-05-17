class Solution {
public:
        //BRUTE FORCE:

    vector<int> nextGreaterElements(vector<int>& nums) {
       
        vector<int>ans(nums.size());

        for(int i = 0 ; i < nums.size(); i++)
        {
            bool flag = false;
            for(int j = i + 1 ;j < nums.size(); j++)
            {
                if(nums[j] > nums[i])
                {
                    ans[i] = nums[j];//ans[0] = 2
                    flag = true;
                    break;
                }
            }
            
            if(!flag)
            {
                for(int j = 0 ; j < i ; j++)
                {
                    if(nums[j] > nums[i])
                    {
                        ans[i] = nums[j];//ans[2]=5
                        flag = true;
                        break;//takes the first Maxmimum
                    }
                }
            }

            if(!flag)
            {
                ans[i] = -1;//ans[1] = -1
            }
        }

        return ans;
    }
};