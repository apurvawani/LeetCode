/*
You are given an integer array nums and you have to return a new counts array. 
The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].


Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.


Example 2:
Input: nums = [-1]
Output: [0]

Example 3:
Input: nums = [-1,-1]
Output: [0,0]
 

Constraints:
1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
*/

class Solution {
public:
    
    vector<int> result;
    
    void findCount(vector<pair<int,int>>& arr, int low, int mid, int high) {
        int i = low, j = mid, k = 0;
        vector<pair<int,int>> temp(high-low+1);
        while(i < mid && j <= high) {
            if(arr[i].first > arr[j].first) {
                result[arr[i].second] += (high-j+1);
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
            }
        }
        
        while(i < mid) {
            temp[k++] = arr[i++];
        }
        
        while(j <= high) {
            temp[k++] = arr[j++];
        }
        
        for(int x = low ; x <= high ; x++) {
            arr[x] = temp[x-low];
        }
    }
    
    void partition(vector<pair<int,int>>& arr, int low, int high) {
        if(low < high) {
            int mid = (low+high)>>1;
            partition(arr, low, mid);
            partition(arr, mid+1, high);
            findCount(arr, low, mid+1, high);   
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        result = vector<int> (len , 0);
        vector<pair<int,int>> arr;
        for(int i = 0 ; i < len ; i++) {
            arr.push_back({nums[i] , i});
        }
        partition(arr, 0, len-1);
        return result;
    }
};