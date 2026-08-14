class Solution {
public:

typedef long long ll;

    int maxScore(vector<int>& cardPoints, int k) {

    int n = cardPoints.size();//

    ll max_sum = 0;

    vector<int>pf_left(n,0);
    
    pf_left[0] = cardPoints[0];

    for(int i = 1;i < n;i++) {
        pf_left[i] = pf_left[i-1] + cardPoints[i];
    }

    vector<int>pf_right(n,0);
    reverse(cardPoints.begin(),cardPoints.end());

    pf_right[0] = cardPoints[0];//

    for(int i = 1;i < n;i++) {
        pf_right[i] = pf_right[i-1] + cardPoints[i];
    }

    int i = k-1;//

    while(i >= 0) {

        ll left_sum = 0;//
     
        ll right_sum = 0;//
        
        left_sum = pf_left[i];//1.

        ll number_of_ele_right = k - (i+1);//0.

        if( number_of_ele_right - 1 >= 0) {
            right_sum = pf_right[number_of_ele_right - 1];
        }

        max_sum = max( left_sum + right_sum ,max_sum);//

        i--;//
    }

    max_sum = max(max_sum,(ll)pf_right[k-1]);//

    return max_sum;

    //TC : O(N)
    //SC : O(N)
 
}

};
