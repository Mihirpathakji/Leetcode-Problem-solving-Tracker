class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int>ans;

        //1. insert every element of nums which is less than the pivot into ans:

        for(auto &it : nums)
        {
            if(it < pivot)
            {
                ans.push_back(it);
            }
        }

        //[9 5 3]

        //2. insert elements equal to nums in ans

        for(auto &it : nums)
        {
            if(it == pivot)
            {
                ans.push_back(it);
            }
        }
        
        //[9 5 3 10 10]

        //3. insert the elements greater than pivot in ans.

        for(auto &it : nums)
        {
            if(it > pivot)
            {
                ans.push_back(it);
            }
        }

        //[9 5 3 10 10 12 14]

        return ans;

        //TC : O(n)
        //SC : O(n)

    }
};