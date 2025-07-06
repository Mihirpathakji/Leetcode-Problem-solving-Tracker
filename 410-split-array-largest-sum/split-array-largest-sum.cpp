class Solution {
public:

    bool istrue(vector<int>& nums, int k,int mid){
        
        int subarraycount = 1;
        int pagesum = 0;
        for(int i = 0; i < nums.size() ;i++){
                
        if(pagesum + nums[i] <= mid ){
                
                pagesum += nums[i] ;  

        }
        else {
           
            subarraycount++;  // for the new subarray the pagesum should again started from the zero  
            pagesum = nums[i];
        
            if( nums[i] > mid || subarraycount > k){
                    return false;
            }
        }

    
        }
    
    return true;
    
    }
    
    int splitArray(vector<int>& nums, int k) {

    // Largest sum of any subarray is minimized is standard Binary search on answer type problem :

    int start = *min_element(nums.begin(),nums.end());

    int sum = 0;
    
    int ans = -1;

    int mid;

    int end ;
    
    for(int i = 0 ;i < nums.size();i++){
            sum += nums[i];
    }
    
    end = sum;
    
    while(start <= end){
            
        mid = start + (end - start)/2;
    
        if(istrue(nums,k,mid)){
            // condition is working i.e the pagesum + arr[i] <= mid  that means the condition is true   

                // i.e the pagesum + arr[i] <= mid
                ans  =  mid;
                end = mid - 1;

        }

        else{

                start = mid + 1;
        }
                        

    }

    return ans;
        
    }
};