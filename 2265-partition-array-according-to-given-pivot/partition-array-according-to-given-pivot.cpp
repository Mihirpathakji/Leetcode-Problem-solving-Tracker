class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int>ans;
        vector<int>left_of_pivot;
        vector<int>right_of_pivot;
        vector<int>pivot1;

        int n = nums.size();

        for(int i = 0 ; i < n; i++)
        {
            if(nums[i] < pivot)
            {
                left_of_pivot.push_back(nums[i]);//[9,5,3]
            }
            else if(nums[i] == pivot)
            {
                pivot1.push_back(nums[i]);//[10,10]
            }
            else
            {
                right_of_pivot.push_back(nums[i]);//[12,14]
            }
        }    

        int i = 0;
        while(i< left_of_pivot.size())
        {
            ans.push_back(left_of_pivot[i]);//[9 5 3]
            i++;//1 2
        }

        i = 0;
        while(i < pivot1.size())
        {
            ans.push_back(pivot1[i]);//[9 5 3 10 10]
            i++;//1 2 
        }

        i = 0;
        while(i < right_of_pivot.size())
        {
            ans.push_back(right_of_pivot[i]);//[9 5 3 10 10 12 14]
            i++;//1 2
        }

        return ans;

        //TC : O(n)
        //SC : O(n)

    }
};