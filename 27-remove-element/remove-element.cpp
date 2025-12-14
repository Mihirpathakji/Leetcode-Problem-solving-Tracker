class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int indx=0;//another helpful index variable.
        for(int i=0;i<n;i++)
        {//i==0;1;2;nums[2]!=3;3
            if(nums[i]!=val)
            {
                nums[indx]=nums[i];//nums[0]=nums[1]==2;nums[1]=nums[2]==2
                //[2 2]
                indx++;//1  2
            }
        }
        return indx;//2->2 elements unique from the val

        //TC:O(n)
        //SC:O(1)
    }
};