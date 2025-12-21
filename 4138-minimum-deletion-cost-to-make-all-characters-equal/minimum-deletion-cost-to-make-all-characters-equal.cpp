class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
       int n=cost.size();
       char max_costing_char;
       long long max_cost=INT_MIN;//I am Using Unordered_map to determine the frequency of each of the character.
       int indx=-1;
       unordered_map<char,long long>mp;
       long long total_cost=0;
       for(int i=0;i<n;i++)
       {
            mp[s[i]]+=cost[i];//67+67=2*67=134+67=201//268//335.Mapping in O(1)Time complexity 
            total_cost+=cost[i];//335
            if(mp[s[i]]>max_cost)
            {
                max_cost=mp[s[i]];//67//134;201;268;335
                max_costing_char=s[i];//'e'
                indx=i;//1//
            }
       }
       if(total_cost==max_cost)
       {
            //No unequal elements are present.
            return 0;//No need to delete any char since all char are already equal.Hence deletion cost is 0.
       }

       //Deletion cost is to delete every single element other than the element at the index=indx(=i)  since the elememt at that index cost the maximum to us.So remove all the elements other than the one at the index =indx.So deletion cost is for every element other than the element at the indx
       long long min_deletion_cost=0;//0
       for(int i=0;i<n;i++)
       {
            if(s[i]!=max_costing_char)
            {
                min_deletion_cost+=cost[i];//268
            }
       }  
    return min_deletion_cost;//268    

    //TC:O(n)
    //SC:O(1)//In worst case also the map will have stored in it the All Lowercase english letters if string consists of all 26 lowercase english letters.Hence even in the worst case the string will store all the 26 characters in it.Hence the space complexity is O(26)  Which is also an constant space complexity .Hence O(1)

    }
};