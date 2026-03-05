class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

    int n = digits.size();
    long long carry = 1;    //since we need Plus one.
    vector<int>ans;
    for(int i = n -1 ; i >= 0; i --)
    {
        long long sum = digits[i] + carry;//10 9+1 == 10  9+1==10
        long long temp = sum % 10;//0 0 0
        ans.push_back(temp);//[0 0 0] 
        carry = sum/10;//1 1 1
    }
    if(carry == 1)
    {
        ans.push_back(carry);//[0 0 0 1]
    }
    //[1 0 0 0]
    reverse(ans.begin(),ans.end());
    return ans;

    //TC:O(n)
    //SC:O(n)

        
    }
};