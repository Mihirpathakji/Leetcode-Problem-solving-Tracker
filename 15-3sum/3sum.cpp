class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=i+1;
        int k=n-1;
        sort(nums.begin(),nums.end());//nlogn
        //[-4 -1 -1 0 1 2 ]
        vector<vector<int>>ans;

        for(int i=0;i<n-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]){
                //skip the iteration for that nums[i].
                //don't went into the while loop otherwise it will generate duplicate triplets.
                continue;
            }
            j=i+1;
            k=n-1;

            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0)
                {   
                    //sum<target_value
                    //increment sum:
                    j++;
                }
                else if(sum>0)
                {
                    //sum>target_value
                    //decrement sum:
                    k--;
                }
                else
                {
                    //we get the required sum.
                    ans.push_back({nums[i],nums[j],nums[k]});//[-1 -1  2] [-1 0 1]
                    j++;
                    k--;
                    while(j<n && nums[j]==nums[j-1])j++;
                    while(k>=0 && nums[k]==nums[k+1])k--;
                }
            }
        }
        return ans;

        //TC:O(n^2)+O(nlogn)==O(n^2)
        //SC:O(1)//O(no.of.triplets)->just to store the answer of input not an extra space
    
    
    }
};