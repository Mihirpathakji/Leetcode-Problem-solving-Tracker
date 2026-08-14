class Solution {
public:

typedef long long ll;

    int maxScore(vector<int>& cardPoints, int k) {

    int n = cardPoints.size();

    ll max_sum = 0;

    if(n == 1) {
        return cardPoints[0];
    }

    vector<int>pf_left(n,0);
    
    pf_left[0] = cardPoints[0];

    for(int i = 1;i < n;i++) {
        pf_left[i] = pf_left[i-1] + cardPoints[i];
    }

    vector<int>pf_right(n,0);
    reverse(cardPoints.begin(),cardPoints.end());//
    //[1,6,5,4,3,2,1].

    pf_right[0] = cardPoints[0];//

    for(int i = 1;i < n;i++) {
        pf_right[i] = pf_right[i-1] + cardPoints[i];
    }

    int i = k-1;//2.
    //combinations : [k,0]
    //

    while(i >= 0) {

        ll left_sum = 0;//0.//since this is a new combination of the left sum and the right sum.//0.
        ll right_sum = 0;//0//0.
        
        left_sum = pf_left[i];//6.//3 elements selected.//6 3 1.

        int number_of_ele_right = k - (i+1);//0.1.2.

        if( number_of_ele_right - 1 >= 0)
        right_sum = pf_right[number_of_ele_right - 1];//0.1.7.

        max_sum = max(left_sum + right_sum,max_sum);//6.8.

        i--;//1.0.-1.
    }

    max_sum = max(max_sum,(ll)pf_right[k-1]);

    return max_sum;
 
}

};
