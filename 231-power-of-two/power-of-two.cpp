class Solution {
public:
    bool isPowerOfTwo(int n) {

       //Brute Force :

       vector<int>binary;
       while(n > 0)
       {
            binary.push_back(n%2);
            n/=2;//8421
       }
       
       //Hint : If a number is power of two -> It contains Exactly 1 set bit in it's binary representation.

       int countof1 = 0;
       for(int i = 0 ; i< binary.size(); i++)
       {
            if(binary[i] == 1)
            {
                countof1++;
            }
       }

        return countof1 == 1;

    }
};