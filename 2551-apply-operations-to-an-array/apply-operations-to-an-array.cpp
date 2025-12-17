class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int j=1;
    while(i<n && j<n)
    {//
        if(nums[i]==nums[j])
        {
            nums[i]*=2;//
            nums[j]=0;
            i+=1;//1  2  3  4 7 9  11
            j+=1;//3 4 5 8 10  12
        }
        else
        {
            i++;//5 6  8 10 12 13
            j++;//6 7 9 11 13 14
        }
        if(j>=n)
        {
            i=0;
            j=i+1;
            break;
        }
    }
    while(i<n  && j<n)
    {//
        if(nums[i]!=0)
        {
            i++;//1 2
            j++;//2 3
        }
        else if(nums[i]==0 && nums[j]==0)
        {
            j++;//3  4 5 8 10 12
        }
        else
        {
            swap(nums[i],nums[j]);
            i++;//2 3 4 5 6 
            j++;//6 7 9 11 13 14
        }
    }
    return nums;
    //TC:O(n)
    //SC:O(1)
    }
};