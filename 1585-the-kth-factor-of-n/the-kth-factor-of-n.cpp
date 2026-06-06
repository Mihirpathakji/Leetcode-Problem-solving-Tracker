class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int>factors_of_n;
        for(int i = 1;i <= n;i++)
        {
            if(n % i == 0)
            {//i is factor of n
                factors_of_n.push_back(i);
            }
        }
        
        // n = 4 . k = 4 -> [1,2,4] -> 3 factors are only there of n 

        //If total no.of factors of n are less than asked no. of factor i.e that no. factor doesn't exists. 

        if(factors_of_n.size() < k)
        {
            return -1;
        }


        return factors_of_n[k-1];
        
    }
};