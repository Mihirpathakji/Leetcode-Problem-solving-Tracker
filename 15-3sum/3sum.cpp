class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Two-Pointer-Technique 
           int n=nums.size();
           sort(nums.begin(),nums.end());
           set<vector<int>>st;
           int l=0;
           int mid=l+1;
           int r=n-1;

           while(l<r-1)
           {
                if(nums[l]+nums[mid]+nums[r]==0)
                {
                    st.insert({nums[l],nums[mid],nums[r]});
                    mid++;
                    r--;
                    if(mid>=r)
                    {
                        l++;
                        mid=l+1;
                        r=n-1;
                    }
                }
                else if(nums[l]+nums[mid]+nums[r]<0)
                {
                    mid++;
                    if(mid==r)
                    {
                        l++;
                        mid=l+1;
                        r=n-1;
                    }
                }
                else
                {
                    r--;
                    if(r<=mid)
                    {
                        l++;
                        mid=l+1;
                        r=n-1;
                    }
                }
           }
           vector<vector<int>>ans(st.begin(),st.end());
           return ans;

        //TC:O(n)
        //SC:O(n)


    }
};