class Solution {
public:
    int maxProduct(int n) {

        //Our goal is to get that problem Accepted anyhow you can use as many spaces as you wanted.Like if you used Maximum space complexity USE IT NOW.Our goal is only to get that problem Accepted.

        int maxi1 = 0;
        int maxi2 = 0;

        while(n) {

            int r = n % 10; //9 5
            n/= 10;//95 9 

            if(r >= maxi1) {
                maxi2 = maxi1;//0 6
                maxi1 = r;//6 9
            }
            else if(r > maxi2) {
                maxi2 = r;
            }

        }

        return maxi1*maxi2;

    }
};