class Solution {
public:

    bool is_possible(long long maxvalue,int n,int index,int maxSum) {

        //We need to check if the sum with this maxvalue = nums[index] is <= maxSum given or not.

        long long sumobtained = maxvalue;

        long long left_sum = 0;
        long long right_sum = 0;

        if(maxvalue-1 > index) {

            long long n1 = (maxvalue-1)*(maxvalue-1+1)/2;//sum from 1 to maxvalue-1.

            long long n2 = (maxvalue-1-index)*(maxvalue-1-index+1)/2;//sum from 1 to maxvalue-1-index.

            left_sum += (n1 - n2);
        } 
        else {

            //maxvalue-1 <=index

            long long n1 = (maxvalue-1)*(maxvalue-1+1)/2;
            long long extra_ones = max(0ll,(index-(maxvalue-1)));

            left_sum += (n1 + extra_ones);
        } 

        if(maxvalue-1 > n-index-1) {

            long long n1 = (maxvalue-1)*(maxvalue-1+1)/2;//sum from 1 to maxvalue-1.

            long long n2 = (maxvalue-1-(n-index-1))*(maxvalue-1-(n-index-1)+1)/2;//sum from 1 to maxvalue-1-(n-index-1).

            right_sum += (n1 - n2);
        } 
        else {

            //maxvalue-1 <=index

            long long n1 = (maxvalue-1)*(maxvalue-1+1)/2;
            long long extra_ones = max(0ll,(n-index-1-(maxvalue-1)));

            right_sum += (n1 + extra_ones);
        } 

        sumobtained += left_sum;
        sumobtained += right_sum;


        return sumobtained <= maxSum;

    }

    int maxValue(int n, int index, int maxSum) {

        //Binary search on possbile maxSum values :

        long long low = 1;
        long long high = maxSum;
        long long ans = 0;

        while(low <= high) {

            long long mid = low + (high-low)/2;//Expected max value of nums[index].

            if(is_possible(mid,n,index,maxSum)) {
                ans = mid;//
                low = mid + 1;                
            }
            else {
                high = mid -1;
            }
        }

        return ans;

        //TC : O(logmaxSum)
        //SC : O(1)
        
    }
};