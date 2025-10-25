class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
    vector<int>ans(2);// constant size vector so the space complexity is also constant.
    int n=numbers.size();
    int i=0;
    int j=n-1;

    while(i<=j)
    {
        if(numbers[i]+numbers[j]==target)
        {
            ans[0]=i+1;
            ans[1]=j+1;
            break;
        }
        else if(numbers[i]+numbers[j]>target)
        {
            j--;
        }
        
        else
        {
            i++;//23
        }
    }
    
    return ans;

    //TC : O(n)
    //SC : O(1)//constant space of 2 elements only 

    }
};