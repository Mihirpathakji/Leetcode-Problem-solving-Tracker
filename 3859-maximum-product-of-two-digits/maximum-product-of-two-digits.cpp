class Solution {
public:
    int maxProduct(int n) {

        //Our goal is to get that problem Accepted anyhow you can use as many spaces as you wanted.Like if you used Maximum space complexity USE IT NOW.Our goal is only to get that problem Accepted.

        vector<int>temp;
        while(n) {

            int r = n % 10;
            n/= 10;

            temp.push_back(r);
        }

        sort(temp.rbegin(),temp.rend());
        return temp[0]*temp[1];
    }
};