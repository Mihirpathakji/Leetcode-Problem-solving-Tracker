class Solution {
public:

    //Generating strings using Recursion.

    void generate_my_string(int& n,int& k,vector<char>&ans,vector<string>& final_ans,int index,int cost)
    {
        
        //First EXPLORE whole path with 0's

        if(ans.size() == n)
        {
            string temp(ans.begin(),ans.end());
            final_ans.push_back(temp);
            return;//Goes out from the deeper root.
        }

        ans.push_back('0');

        generate_my_string(n,k,ans,final_ans,index+1,cost); //EXPLORE THE ENTIRE UNIVERSE OF 0.

        ans.pop_back();//Went to explore other paths.

        //SECOND NOW Explore the whole path with 1's :

        //There are conditions:

        bool no_consecutive_one = (ans.empty() || ans.back()!='1');
        bool within_cost_limit = (index + cost) <= k;
        
        if(no_consecutive_one && within_cost_limit )
        {
            ans.push_back('1');

            //EXPLORE THE ENTIRE PATH OF '1'
            generate_my_string(n,k,ans,final_ans,index+1,cost+index);

            ans.pop_back();
        }

    }

    vector<string> generateValidStrings(int n, int k) {

        //lets generate them with recursion.

        int cost = 0;
        int index = 0;
        vector<char>ans;
        vector<string>final_ans;
        generate_my_string(n,k,ans,final_ans,index,cost);
        
        return final_ans;
    }

};