class Solution {
public:
    int mySqrt(int x) {
        //Brute Force :looping from 1 till root x
        //x=256;
        if(x==0)
        {
            return 0;
        }
        int ans=1;//1;
        for(long long int i=1;i*i<=x;i++)
        {//i*i=1<=256  ;i*i=4<=256;i=3;i=4;i=5;i=6;i=7;i=8;i=9;i=10;i=11;i=12;i=13;i=14;i=15';i=16;i=17
            if(i*i<=x)
            {//1<=1
                ans=i;//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
            }
        }
        return ans;
        //TC:O(Sqrt(n))
        //SC:O(1)
    }
};