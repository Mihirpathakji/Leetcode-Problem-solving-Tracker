class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());//[2 2 4 5]
        int i=0;
        int count1=0;
        int smallest_sum=0;
        while(count1<k)
        {
            smallest_sum+=nums[i];//100
            i++;
            count1++;
        }

        int j=n-1;//0
        int count=0;
        int largest_sum=0;
        while(count<k)
        {
            largest_sum+=nums[j];//2
            j--;//0 -1
            count++;//1 2 
        }

        int abs_diff=abs(smallest_sum-largest_sum);
        return abs_diff;
    }
};