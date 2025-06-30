class Solution {
public:
    int mySqrt(int x) {
// the sqrt(x) always lies between 0  and the number  x . We can consider the 0 as the start and the x as the end therby apply the simple binar search

    int start = 0;
    int end = x;
   long long int mid ;
    long long int ans = -1;

    while(start <= end){
            mid  = start  + (end - start)/2;

            if(mid*mid == x){
                //i.e the mid is the sqrt of the x 
                return mid;  // return that sqrt (x)
            }
            else if(mid * mid < x ){
                // lekin for the x = 10 mid *mid is 4 then 4 is the possible answer of sqrt(10) so you need to store it in another variable 
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid -1;
            }
    }
        return ans;
    }
};