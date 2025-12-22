class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Optimal Solution:
        int n=nums.size();
        int el;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                el=nums[i];
                count++;
            }
            else if(el==nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
    
        return el;
        //TC:O(n)
        //SC:O(1)
    
    }
};