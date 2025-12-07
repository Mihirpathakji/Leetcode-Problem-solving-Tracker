class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {

    int n=arr.size();
    int i=0;
    int j=n-1;
    vector<int>ans(n);
    int k=n-1;//last index 

    while(i<j)
    {
        if(arr[i]*arr[i]<arr[j]*arr[j])
        {
            ans[k]=(arr[j]*arr[j]);
            j--;
        }
        
        else if(arr[i]*arr[i]>arr[j]*arr[j])
        {
            ans[k]=(arr[i]*arr[i]);
            i++;
        }
        else
        {
            ans[k]=(arr[i]*arr[i]);
            i++;
        }
        k--;
    }
    ans[k]=(arr[i]*arr[i]);
    return ans;
    
    //100 16 9 1 0 ->result of push_back better is kept an index variable . 
    
    }

};