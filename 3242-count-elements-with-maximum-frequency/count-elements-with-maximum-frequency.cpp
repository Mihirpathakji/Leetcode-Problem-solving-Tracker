class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {   
        int x=nums.size();
        unordered_map<int,int>mp1;
      
        // Precompute :

        for(int i=0;i<x;i++)
        {
            mp1[nums[i]]+=1;
        }

    //  O(x)*O(1)  == O(x)

        int maxi=INT_MIN;
        int y=mp1.size();
        for(int i=1;i<=100;i++)
        {
            if(mp1[i]>maxi)
            {
                maxi=mp1[i];  
            }
        }


        int total_frequency=0;
        for(int i=1;i<=100;i++)
        {
            if(mp1[i]==maxi)
            {
                total_frequency+=maxi;
            }
        }
        return total_frequency;
        
        // Tc : O(x)


    }
};