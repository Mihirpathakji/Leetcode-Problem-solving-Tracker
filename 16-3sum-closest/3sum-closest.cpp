class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;    
        int sum;
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<n-2;i++)
        {    sum=0;
             int j=i+1;//2
             int k=n-1;//n-1
            while(j<k)
            {
                sum=nums[i]+nums[j]+nums[k];
                if(sum==target)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    j++;//2
                    int abs_diff=abs(sum-target);
                    ans.push_back(abs_diff);
                    mp[abs_diff]=sum;
                }
                else
                {
                    k--;
                    int abs_diff=abs(sum-target);
                    ans.push_back(abs_diff);
                    mp[abs_diff]=sum;
                }
            }
        }
        int mini=*min_element(ans.begin(),ans.end());
        return mp[mini];
    }
    
    //TC:O(n^2+nlogn)
    //SC:O(1)
};