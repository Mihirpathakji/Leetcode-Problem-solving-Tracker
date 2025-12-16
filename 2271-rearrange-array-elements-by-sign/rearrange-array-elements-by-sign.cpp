class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      int n=nums.size();
      vector<int>positives;
      vector<int>negatives;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                negatives.push_back(nums[i]);
            }
            else
            {
                positives.push_back(nums[i]);
            }
        }
        int j=0;
        int i=0;
        for(int index=0;index<n;index++)
        {//index==1;2;3;4;5
            if(index%2==0)
            {
                nums[index]=positives[i];//nums[0]=positives[0]==3
                i++;//1 nums[2]=positives[1]==1//2;nums[4]=positives[2]==2
            }   
            else
            {
                nums[index]=negatives[j];//nums[1]=negatives[0]=-2//nums[3]=-5
                j++;//1//2 nums[5]==-4
            }
        }
    //nums[]=[3 -2 1 -5 2 -4]
        return nums;

        //TC:O(n)
        //SC:O(n)
    }
};