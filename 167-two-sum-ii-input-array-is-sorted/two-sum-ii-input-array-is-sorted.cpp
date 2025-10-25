class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        vector<int>ans(2);
        int start=0;
        int end=n-1;
        while(start<end)
        {
            //case1 :
            if(numbers[start]+numbers[end]==target)
            {
                ans[0]=(start+1);// since to get the same index when the numbers would be 1 based .
                ans[1]=(end+1);
                return ans;
            }

            else if(numbers[start]+numbers[end]>target)
            {
                //decrease our sum Value;
                end--;
            }
            else
            {
                //Our sum is lesser than the Target.Increase it inorder to reach the Target value.
                start++;
            }
        }
        return ans;// just returning an empty vector to match the function call type.
    }
};