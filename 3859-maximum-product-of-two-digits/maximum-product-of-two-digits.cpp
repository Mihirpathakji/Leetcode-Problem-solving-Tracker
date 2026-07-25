class Solution {
public:
    int maxProduct(int n) {

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