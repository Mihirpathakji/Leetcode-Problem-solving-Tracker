class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();//1
        int ops=0;
        int indx=-1;//keep it some another value men 
        unordered_map<int,int>mp;
        for(int start=n-1;start>=0;start--)
        {
            if(mp.count(nums[start]))
            {
                //Get that index.
                indx=start;//1 0 
                break;//till that index you need to do the removal.
            }
            else
            {
                mp[nums[start]]++;
            }
        }
        if(indx==-1)
        {
            //no duplicates -> no operations needed
            return 0;
        }
        int i=0;
        while(i<=indx)
        {
            i+=3;
            ops++;
        }
        return ops;

    //TC:O(n)
    //SC:O(n)

    }
};