class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        unordered_map<int,int>mp1;
        vector<int>ans;
        for(int i = 0; i< A.size(); i++)
        {
            mp1[A[i]]++;
            mp1[B[i]]++;
            int  count = 0;
            for(int i = 0 ; i< mp1.size(); i++)
            {
                if(mp1[i] >= 2)
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};