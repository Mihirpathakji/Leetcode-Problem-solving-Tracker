class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        int n  = nums.size();
        int n1 = queries.size();

        sort(nums.begin(),nums.end());

        vector<int>ans;

        for(int i = 0;i < n1; i++)
        {
            long long int sum = 0;//0
            vector<int>temp;//

            for(int j = 0; j < n ;j++)
            {
                sum += nums[j];//4 0  5 0 2 3 //4 9 11 10 // 469781

                if(sum <= queries[i])
                {   
                    temp.push_back(nums[j]);//[2 3] //[4 9 1] //469781
                }   
                else
                {
                    break;
                }
            }
 
            ans.push_back(temp.size());//[2,3] //
        }

        return ans;
        
    }
};