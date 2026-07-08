class Solution {
public:

    long long MOD = 1e9 + 7;
    typedef long long ll;
    //IMPORTANT TIPS : Whenever using a power function.Firstly ,It returns you a double value .Secondly , if power of 10 is going very very larger than the power func will OVERFLOW EVEN THE long long values even after MOD 1e9+7 thrice or more. BEST PRACTICE  : Instead of power function. Use a own built vector where of type long long where power10[K] gives the kth power of 10. In the power10[] vector computation we will Repeatedly keep on MOD by 1e9+7.So, that the resulting value When repeatedly MOD through each iteration will never exceed long long. 

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int n = s.length();
        
        vector<long long>power10(n,0);

        power10[0] = 1;//pow(10,0) = 1.
        for(int i = 1;i <n;i++) {
            power10[i] = (power10[i-1]*10) % MOD;
        }
        
        vector<long long>prefix_sum(n,0);

        prefix_sum[0] = s[0]-'0';

        for(int i = 1;i < n;i++) {
            prefix_sum[i] = prefix_sum[i-1] + (s[i]-'0');
        }

        vector<long long>prefix_integer(n,0);
        prefix_integer[0] = s[0]-'0';
            
        for(int i = 1;i < n;i++) {
            if(s[i] - '0' == 0) {
                prefix_integer[i] = prefix_integer[i-1];
            }
            else {
                prefix_integer[i] = ( (prefix_integer[i-1] * 10) % MOD + (s[i]-'0')) % MOD;
            }
        }

        vector<int>Non_Zero_Digits_Upto(n,0);//Prefix Non Zero Digits count. 

        if(s[0]-'0' == 0)
        Non_Zero_Digits_Upto[0] = 0;

        else 
        Non_Zero_Digits_Upto[0] = 1; 

        for(int i = 1;i < n;i++) {
            if(s[i]-'0'!= 0) {
                Non_Zero_Digits_Upto[i] = Non_Zero_Digits_Upto[i-1] + 1;
            }   
            else {
                Non_Zero_Digits_Upto[i] = Non_Zero_Digits_Upto[i-1];
            }
        }

        int n1 = queries.size();
        vector<int>answer(n1);

        for(int i = 0;i < n1;i++) {

            int l = queries[i][0];
            int r = queries[i][1];

            //k = Non Zero Digits in the subarray [l,r].

            int k = -1;
            long long product = -1;

            if(l == 0) {
                
                //[0,r].
                long long x = prefix_integer[r];
                answer[i] =  ( (long long ) x * prefix_sum[r]) % MOD;
            }

            else {

                k = Non_Zero_Digits_Upto[r] - Non_Zero_Digits_Upto[l-1];//0
    
                product =  ( prefix_integer[l-1]* power10[k] ) %MOD;

                long long x = (prefix_integer[r] - product + MOD)%MOD;//Since can May become negative so i added MOD thereby done % MOD.
                long long sum = (prefix_sum[r]-prefix_sum[l-1] + MOD)%MOD;//Since can may become negative so i ADDED MOD thereby taken % MOD.

                answer[i] = (x*sum) % MOD;
            }

        }

        return answer;

        //TC : O(q.size() + n)
        //SC: O(n) n = str.length().

    }
};