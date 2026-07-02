class Solution {
public:

    bool is_possible(long long target,int n,int index,int maxSum) {

        long long curr_sum = 0;
        curr_sum += target;

        long long left_sum = 0;
        long long extraOnes_left = max(0ll,index-(target-1));
        if(target-1 > index) {
            left_sum += ((target-1)*(target)/2 -((target-1-index)*(target-1-index+1)/2));
        }
        else {
            left_sum += (target-1)*(target)/2 + max(0ll,index-(target-1));
        }

        long long right_sum = 0;
        long long extraOnes_right = max(0ll,n-index-1-(target-1));
        long long n2 = min(target-1,(long long)n-index-1);

        if(target-1 > n-index-1) {
            right_sum += ((target-1)*(target)/2 -((target-1-(n-index-1))*(target-1-(n-index-1)+1)/2));
        }
        else {
            right_sum = ( (target-1)*(target)/2 + extraOnes_right); 
        }

        curr_sum += left_sum;
        curr_sum += right_sum;

        return curr_sum <= maxSum;

    }

    int maxValue(int n, int index, int maxSum) {

        //Brute force :

        long long target = maxSum;
        long long max_ans = LLONG_MIN;

        long long low = 1;
        long long high = maxSum;

        while (low <= high) {
        
            long long mid = low + (high-low)/2;
            if(is_possible(mid,n,index,maxSum)) {
                max_ans = mid;
                low = mid +1;
            }
            else {
                high = mid-1;
            }
        }

        return max_ans;

        //TC : O(logmaxSum)
        //SC : O(1)
        
    }
};