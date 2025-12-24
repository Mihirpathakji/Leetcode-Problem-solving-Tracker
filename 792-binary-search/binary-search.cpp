class Solution {
public:

    int binary_search(vector<int>&arr,int low,int high,int target)
    {

        //base case:
        if(low>high)
        {
            return -1;
        }
        int mid=low+ (high-low)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[mid]>target)
        {
            return binary_search(arr,low,mid-1,target);
        }
        else
        {
            return binary_search(arr,mid+1,high,target);
        }
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary_search(nums,0,n-1,target);
    }


    //TC:O(log2(n))
    //SC:O(log2(n))//The Stack Space that you are using in the Recursion to hold all recursive calls.
};