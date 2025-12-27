class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
        {
            return 0;
        }
        int ans=1;
        //There is no array , no vector.Your search space for the Binary search will be [Minimum_possible_ans,Maximum_possible_ans]
        int low=1;
        int high=sqrt(x);//sqrt(INT_MAX)

        while(low<=high)
        {
            long long int mid=low+(high-low)/2;//1
            //Only 3 cases are possible for no. mid with respect to what aksed :-

            if(mid*mid==x)
            {
                return mid;
            }
            else if(mid*mid<x)
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;//only executed when x dosent have perfect sqrt   
        //TC:O(lo2(x))
        //SC:O(1)
 }
};