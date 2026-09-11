class Solution {
public:
    int maxProduct(int n) {

        int maxi1 = 0; 
        int maxi2 = 0;

        while(n) {

            int r = n % 10;
            n/= 10;

            if(r > maxi1) {
                maxi2 = maxi1;
                maxi1 = r;
            }
            else if(r > maxi2) {
                maxi2 = r;
            }

        }

        return maxi1*maxi2;

        //TC : O(logn)
        //SC : O(1)

    }
};