class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        int a=0;
        int b=a+1;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());//Without sorting the Two-Pointer Technique cant be used.

        //Two-Pointer-Technique.Move only the Two-Pointers c and d Only Move the two -pointers other all pointers must be kept constant. 

        //Generate-Quadrupulets.

        for(int a=0;a<n-3;a++)
        {
            if(a>0 && nums[a]==nums[a-1])continue;
            for(int b=a+1;b<n-2;b++)
            {
                if(b>1 && nums[b]==nums[b-1] && b!=a+1)continue;  

                int c=b+1;
                int d=n-1;
                //Move only the Two-Pointers c and d Kept all the other Pointers a,b constant 
                while(c<d)
                {
                    long long int sum=(long long int)nums[a]+(long long int)nums[b]+(long long int)nums[c]+(long long int)nums[d];
                    if(sum==target)
                    {
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        c++;
                        while(c<d && nums[c]==nums[c-1])
                        {
                            c++;
                        }
                        d--;
                        while(d>=0 && nums[d]==nums[d+1])
                        {
                            d--;
                        }
                    }
                    else if(sum<target)
                    {
                        c++;
                    }
                    else
                    {
                        d--;
                    }
                }
            }
        }
        return ans;

        //TC:O(n^3+nlogn)
        //SC:O(1)(NO EXTRA SPACE)

    }
};