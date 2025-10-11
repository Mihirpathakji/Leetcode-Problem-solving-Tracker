class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        // 1. vector integer directly into a set s   : 1.vector<int>nums(s.begin(),s.end())    2. vector<int>nums  -> nums.assign(s.begin(),s.end()) 
        // 2. set directly int to a vector integer : s.insert(nums.begin(),nums.end())  2.set<int>s(nums.begin(),nums.end(  ))

        set<int>s;
        s.insert(nums.begin(),nums.end());// nlogn n

        nums.assign(s.begin(),s.end());// n  


        // vector-> idexing is possible but in the set indexing is not possible we need to iterate through it's elements 

        //Tc : O(nlogn + n) == O(n)
        //Sc : O(s.size())
 
        return s.size();
    }
};