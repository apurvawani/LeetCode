/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
 

Constraints:
1 <= numRows <= 30
*/

/*
Appraoch:
-> Given rowNum & colNum you can get element in Pascal Triangle using binomial coefficient - C(rowNum-1, colNum-1)

-> In each row first & last element is same & equal to 1.
-> We can get the rremaining element by addition of above two elements of that element.
-> T.C - O(numRows^2)
	S.C - O(numRows^2)

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int i = 0 ; i < numRows ; i++) {
            ans[i].resize(i+1);
            ans[i][0] = ans[i][i] = 1;
            
            for(int j = 1 ; j < i ; j++) {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j]; 
            }
        }
        return ans;
    }
};