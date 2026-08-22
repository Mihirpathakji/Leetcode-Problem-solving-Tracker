class Solution {
public:
    bool checkDivisibility(int n) {

        vector<int>v;
        int num = n;

        long long val1 = 0;
        long long val2 = 1;

        while(num){
            val1 += num%10;
            val2 *= num%10;

            num/=10;

        }

        long long final = val1 + val2;
        return (n%final) == 0;
        
    }
};