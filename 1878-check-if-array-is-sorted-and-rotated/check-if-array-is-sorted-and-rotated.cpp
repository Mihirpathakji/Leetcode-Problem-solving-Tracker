class Solution {
public:
    bool check(vector<int>& nums) {

        vector<int>original = nums;
        sort(original.begin(),original.end());//nlogn
        vector<int>nums2 = nums;

        int k = nums.size();//n

        while(k)
        {
            
            for(int i =0; i < nums.size(); i++)
            {
                nums2[(i+1)%nums2.size()] = nums[i];//2nd time rortation che i.e nums should be now the nums rotated once .so that the nums2 will be nums after twice rotations.
            }
            
            if(nums2 == original)
            {
                return true;
            }

            k--;

            nums = nums2;

        }
        
        //TC : O(nlogn) + O(n*(n+2*n)) == O(nlogn) + O(n*(3*n)) == O(nlogn) + O(n^2)

        return false;

    }
};