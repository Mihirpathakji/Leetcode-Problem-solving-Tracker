class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());//O(nlogn)
        int mini_absdiff=INT_MAX;
        int closest_sum=0;//That what we wanted to find out.

    //  Technique to Generate all the Triplets:
        for(int k=0;k<n-2;k++)
        {   
            int i=k+1;
            int j=n-1;
            //Keeping k constant and only changing the i and j two pointers.
            while(i<j)
            {
                int sum=nums[k]+nums[i]+nums[j];
                if(sum==target)
                {
                    return sum;
                }
                else if(sum<target)
                {
                    //-3<1  ->  
                    int curr_absdiff=abs(sum-target);
                    if(curr_absdiff<mini_absdiff)
                    {
                        //sum is closer 
                        mini_absdiff=curr_absdiff;
                        closest_sum=sum;
                    }
                    i++;
                }
                else
                {
                    //i would calculate the minimum absolute difference.
                    int curr_absdiff=abs(target-sum);
                    if(curr_absdiff<mini_absdiff)
                    {   
                        mini_absdiff=curr_absdiff;
                        closest_sum=sum;
                    }
                    j--;
                }
            }
        }
        return closest_sum;

        //TC :O(n^2+nlogn)
        //SC:O(1)


    }
};