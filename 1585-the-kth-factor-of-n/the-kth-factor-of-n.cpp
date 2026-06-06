class Solution {
public:
    int kthFactor(int n, int k) {

        vector<int>factors_of_n;
        for(int i = 1;i <= n;i++)
        {
            if(n % i == 0)
            {
                factors_of_n.push_back(i);
            }
        }

        if(factors_of_n.size() < k)
        {
            return -1;
        }

        return factors_of_n[k-1];
        
        //TC : O(n)
        //SC : O(n)
 
 
    }
};