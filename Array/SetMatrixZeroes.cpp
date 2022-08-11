/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1

*/

/*
Approach:
Brute - 
1. Traverse through the matrix & if you find a 0 change the entire row & column with INT_MAX(or some other value which is not in the input value range).
2. Now traverse the matrix & replace INT_MAX with 0. That's the answer. 

T.C - O((n*m)*(n+m))
S.C - O(1)

Better - 
1. Use 2 dummy arrays one of size n(dummyR) other of size m(dummyC).
2. Now traverse through the matrix & if matrix[i][j] = 0 then dummyR[i] = 0 & dummyC[j] = 0.
3. Traverse the matrix again if dummyR[i] = 0 or dummyC[j] = 0 then matrix[i][j] = 0.

T.C - O(n*m)
S.C - O(max(n,m))

Optimal - 
1. Instead of creating 2 different arrays use the first row as dummyR & first column as dummyC.
2. Since (0,0) location is overlapping, create a variable col0 for column 0 & use matrix[0][0] for row 0.
3. Set col0 = false if 0 is present in column 0 of matrix.
4. Now traverse the matrix in reverse direction & if matrix[i][0] = 0 or  matrix[0][j] = 0 then matrix[i][j] = 0.
5. If col0 is false then matrix[i][0] = 0;

T.C - O(n*m)
S.C - O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool col0 = true;
        for(int i = 0 ; i < r ; i++) {
            if(matrix[i][0] == 0)
                col0 = false;
            for(int j = 1 ; j < c ; j++) {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for(int i = r-1 ; i >= 0 ; i--) {
            for(int j = c-1 ; j >= 1 ; j--) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(!col0)
                matrix[i][0] = 0;
        }
    }
};
