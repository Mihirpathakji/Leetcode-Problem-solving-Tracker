class Solution {
public:

    void merge(vector<int>&nums,int start,int mid,int end)
    {
        int i = start;//1st of 1st arr = [start,mid].
        int j = mid+1;//1st of 2nd arr = [mid+1,end].
        vector<int>temp;


        while(i <= mid && j<= end)
        {
            if(nums[i] <= nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(j <= end)
        {
            temp.push_back(nums[j]);
            j++;
        }

        while(i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }

        //Assigning all elements into the Our original nums:

        for(int index = 0; index < temp.size(); index++)
        {
            nums[index + start] = temp[index];
        }
    }

    void mergesort(vector<int>&nums,int start,int end)
    {

        //Base case for Recursive call :

        if(start < end)
        {
            int mid = start + ( end- start )/2;
            mergesort(nums,start,mid);//For left portion of arr.
            mergesort(nums,mid+1,end);//For right portion of arr.
            merge(nums,start,mid,end);//O(n)
        }
    }//O(logn)
    //TC:O(nlogn)

    vector<int> sortArray(vector<int>& nums) {

        mergesort(nums,0,nums.size()-1);
        return nums;


        //TC:O(nlogn)
        //SC:O(n)

    }
};