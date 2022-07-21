/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:
-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 10^4 calls will be made to addNum and findMedian.
*/

class MedianFinder {
public:
    
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int count;
    
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if(left.empty())
            left.push(num);
        else if(num > left.top())
            right.push(num);
        else
            left.push(num);
        
        int l1 = left.size() , l2 = right.size();
        if(l1 - l2 > 1) {
            right.push(left.top());
            left.pop();
        }
        else if(l2 - l1 >= 1) {
            left.push(right.top());
            right.pop();
        }
        count++;
    }
    
    double findMedian() {
        if((count & 1) != 0) {
            return (double)left.top();
        }
        else {
            return (left.top() + right.top())/2.0; 
        }
    }
};
