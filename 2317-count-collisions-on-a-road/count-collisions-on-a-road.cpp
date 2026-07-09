class Solution {
public:
    int countCollisions(string directions) {

        int collisions = 0;
        int n = directions.length();

        int i = 0;
        int j = n-1;

        while(i < n && directions[i] == 'L') {
            i++;
        }

        while(j >=0 && directions[j] == 'R') {
            j--;
        }

        while(i <= j) {
            if(directions[i] == 'L' || directions[i] == 'R') {
                collisions++;
            }
            i++;
        }

        return collisions;
        
        //TC : O(n)
        //SC : O(1)
        //Error at an unknow line no. which does not exists  i.e -> 1.May be Invalid indices got accessed.

    }
};