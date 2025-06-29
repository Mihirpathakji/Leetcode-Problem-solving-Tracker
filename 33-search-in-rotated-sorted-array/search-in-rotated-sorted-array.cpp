class Solution {
public:
    int binarysearch(vector<int>& nums, int target,int start,int end){
        int  mid;
        while(start <= end){
            mid = start + (end -start)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                    end = mid -1; 
            }
            else{
                start  = mid +1 ;
            }
        }
        return -1;
    } 

    int printPivotindex(vector<int>&nums){
        int start = 0 ;
        int end = nums.size() -1;
        int mid;

        while(start < end){
            mid = start + (end - start)/2;
            if(nums[mid] >= nums[0]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
            
        }
        return end;
    }

    int search(vector<int>& nums, int target) {

        int pivot = printPivotindex(nums);                                  
        if(nums[pivot] <= target && target <= nums[nums.size()-1]){
         return   binarysearch(nums,target,pivot,nums.size()-1);
        }
        else{
          return  binarysearch(nums,target,0,pivot-1);
        }
        
    }   
};