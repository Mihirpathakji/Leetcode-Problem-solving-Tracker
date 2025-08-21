class Solution {
public:
    int findGCD(vector<int>& nums) {
        //Using Euclidean Algorithm to Find GCD / HCF ->Optimal way
        int a =*min_element(nums.begin(),nums.end());
        int b=*max_element(nums.begin(),nums.end());

        while(a>0 && b >0){
            if(a>b){// a=3 b=7  
                a=a%b;//3 >1  -> 0 return that b which was earlier 1 
            }
            else{
                b=b%a;// b=1
            }
        }
        
        if(a==0){
            return b;
        }

        return a;// for b==0 and a==b a=11 && b=11 gcd(11,11)=11
        //Tc :O(log_base(phi)(min(a,b))); 
    }
};