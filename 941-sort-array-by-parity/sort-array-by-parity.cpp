class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        //since the q itslef states that the final array can be return in "ANY ORDER" .Hence the sorting was not even Required.
        int n=nums.size();
        int i=0;//0
        int j=n-1;//3
        while(i<j)
        {
            if(nums[i]%2==0)
            {   
                i++;//1
            }
            else
            {
                //nums[i] not even then make it even 
                if(nums[j]%2==0)
                {
                    swap(nums[i],nums[j]);//[4 1 2 3]//[4 2 1 3]
                    i++;//1  2
                    j--;//2   1
                }
                else
                {
                    j--;
                }
            }
        }
        return nums;

    //TC:O(n)
    //SC:O(1)

    }
};