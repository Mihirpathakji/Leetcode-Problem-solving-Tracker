class Solution {
public:

    long long MOD = 1e9 + 7;

    //Whenever a product exceeds even long long use % MOD, MOD = 1e9+7.

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        int n = s.length();
        
        vector<long long>power10(n,0);

        power10[0] = 1;
        for(int i = 1;i <n;i++) {
            power10[i] = (power10[i-1]*10)%MOD;
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
                prefix_integer[i] = ( (prefix_integer[i-1]*10) % MOD + (s[i]-'0')) % MOD;
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

                k = Non_Zero_Digits_Upto[r] - Non_Zero_Digits_Upto[l-1];
    
                product =( ( ( prefix_integer[l-1]* power10[k] ) % 
                MOD ) % MOD ) %MOD;

                long long x = (prefix_integer[r] - product + MOD)%MOD;
                long long sum = (prefix_sum[r]-prefix_sum[l-1] + MOD)%MOD;

                answer[i] = (x*sum) % MOD;
            }

        }

        return answer;

        //TC : O(q.size() + n)
        //SC: O(n) n = str.length().

    }
};