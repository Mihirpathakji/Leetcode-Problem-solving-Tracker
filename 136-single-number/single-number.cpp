class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]+=1;//2 
        }

        for(auto it :mp)
        {   
            if(it.second==1)
            {
                return it.first;
            }
        }
        return 0;
    
    //TC : O(2*n)==O(n)
    //SC : O(n)
    
    }
};