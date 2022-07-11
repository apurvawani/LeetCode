/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 
Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
 

Constraints:
1 <= arr.length <= 3 * 10^4
1 <= arr[i] <= 3 * 10^4
*/

class Solution {
public:
    const unsigned int mod = 1000000007;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,0);
        stack<int> s1;
        for(int i = 0 ; i < n ; i++) {
            while(!s1.empty() && arr[s1.top()] > arr[i])
                s1.pop();
            if(s1.empty())
                left[i] = i;
            else
                left[i] = i - s1.top() - 1;
            s1.push(i);
        }
        
        vector<int> right(n,0);
        stack<int> s2;
        for(int i = n-1 ; i >= 0 ; i--) {
            while(!s2.empty() && arr[s2.top()] >= arr[i])
                s2.pop();
            if(s2.empty())
                right[i] = n-1-i;
            else
                right[i] = s2.top() - i - 1;
            s2.push(i);
        }
        
        int result = 0;
        for(int i = 0 ; i < n ; i++) {
            left[i]++;
            right[i]++;
            result += (left[i]%mod * right[i]%mod * arr[i]%mod)%mod;
            result = result%mod;
        }
        return result;
    }
};