class Solution {
public:
    long long sumAndMultiply(int n) {

        vector<long long>my_num;
        long long sum = 0;
        while(n) {
            long long rem = n%10;
            if(rem) {
                sum += rem;
                my_num.push_back(rem);
            }   
            n/=10;
        }

        long long x = 0;
        reverse(my_num.begin(),my_num.end());//1234

        int n1 = my_num.size();

        for(int i = 0;i < n1;i++) {
            x += (my_num[i]*pow(10,(n1-i-1)));//1000 +=200 += 30 +=4
        }

        return x*sum;

    }
};