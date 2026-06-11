class Solution {
public:
    bool isPowerOfTwo(int n) {

        //Bit Manipulation :
        if(n == 0)
        {
            return false;
        }
        
        return ( (n & (n-1LL) )== 0);

        //TC : O(1)
        //SC : O(1)
        
    }
};