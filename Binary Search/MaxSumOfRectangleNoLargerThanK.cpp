/*
Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
It is guaranteed that there will be a rectangle with a sum no larger than k.

 
Example 1:
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

Example 2:
Input: matrix = [[2,2,-1]], k = 3
Output: 3
 

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 100
-100 <= matrix[i][j] <= 100
-10^5 <= k <= 10^5
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 1 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                matrix[i][j] += matrix[i-1][j];
            }
        }
        
        int result = INT_MIN;
        for(int r1 = 0 ; r1 < m ; r1++) {
            for(int r2 = r1 ; r2 < m ; r2++) {
                set<int> s;
                s.insert(0);
                int total = 0;
                for(int c = 0 ; c < n ; c++) {
                    total += (matrix[r2][c] - (r1==0 ? 0 : matrix[r1-1][c]));
                    auto x = s.lower_bound(total-k);
                    if(x != s.end())
                        result = max(result, total - *x);
                    
                    s.insert(total);
                }
            }
        }
        return result;
    }
};