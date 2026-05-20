class Solution {
public:
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        unordered_map<int,int>mp1;
        vector<int>ans;

        int i = 0;
        int count = 0;

        while(i < A.size())
        {
            mp1[A[i]]++;
            mp1[B[i]]++;
            if(mp1[A[i]] >= 2)
            {
                count++;
            }
            if(A[i]!=B[i] && mp1[B[i]] >= 2)
            {
                count++;
            }
            ans.push_back(count);
            i++;
        }

        return ans;

        //TC : O(n)
        //SC : O(n)
    }
};