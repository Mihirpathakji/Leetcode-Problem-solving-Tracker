class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moree's Voting Algorithm:TC:O(n) & SC:O(1)
        int n=nums.size();
        int element=-1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(count==0)
            {
                count=1;
                element=nums[i];
            }
            else if(nums[i]==element)
            {
                count++;//Tracks the frequency of that element.
            }
            else
            {
                count--;
            }
        }
        //element would have got the Majority element in it since it is mentioned in Question that the Majority element always exists.
        
        return element;

        //suppose it dosent exists than we need to do a check and return -1  since the majority element dosent exists.You need to track the frequency of the element that you have founded check whether it is greater than n/2 or not??

        int freq=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==element)
            {
                freq++;
            }
        }
        if(freq<=n/2)
        {
            return -1;
        }
        else
        {
            return element;
        }


        //TC:O(n)
        //SC:O(1)
    }
};