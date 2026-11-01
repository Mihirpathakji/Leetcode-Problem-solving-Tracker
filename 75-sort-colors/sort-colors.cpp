class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int i = 0;//0
        int j = 0;//1
        int k = n-1;//2.Bcz 2 is at the last position.

        while(j <= k) {

            if(nums[j] == 2) {
                swap(nums[j],nums[k]);
                k--;
                //portion : nums[j]...nums[k] is unknown the nums[k] may contains any value so swapping with the nums[j] doesn't gurantee that which value the nums[j] will got in...
                //nums[j] may get 0 or another 2. thereby we can do the j++.    
            }
            
            else if(nums[j] == 0) {
                swap(nums[i],nums[j]);
                i++;
                j++;//In dutch national flag algo. nums[i]...nums[j-1] portion surely contains the 1 . so nums[i] will contains 1 so doing swapping with the nums[j] got nums[j] a right value.
                //thereby we can do the j++;
            }
            else {
                j++;
            }
        }

        //TC : O(n)
        //SC : O(1)

    }
};