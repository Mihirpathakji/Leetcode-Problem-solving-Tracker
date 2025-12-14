class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int n=nums.size();
    int a=0;
    int b=a+1;
    vector<vector<int>>ans;

    //[-2 -1 -1 1 1 2 2 ]n=7
    //Generating Qudrupulet of 4-Numbers: 
    for(int a=0;a<n-3;a++)
    {
        //a==1
        if(a>0 && nums[a]==nums[a-1])continue;
          for(int b=a+1;b<n-2;b++)
           {//b=2 3 
                if(b>1 && nums[b]==nums[b-1] && b!=a+1)continue;

                int c=b+1;//3
                int d=n-1;//6
                while(c<d)
                {
                    long long int sum=((long long int)nums[a]+(long long int )nums[b]+(long long int)nums[c]+(long long int)nums[d]);//-2//2 //2 
                    if(sum==target)
                    {
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});//[-2 -1 1 2 ],[-1 -1 1 1]
                        c++;//4 5 
                        d--;//5 3
                        while(c<d && nums[c]==nums[c-1]) {
                            c++;//5
                        }
                        while(c<d &&  nums[d]==nums[d+1])  {
                            d--;
                        }           
                    }
                    else if(sum<target)
                    {
                        c++;//3
                    }
                    else
                    {
                        d--;//5  4 
                    }
                }   
             }
    }
    return ans;
    //TC:O(n^3+nlogn)
    //SC:O(no.of.unique.Quadrupulets)
    }
};