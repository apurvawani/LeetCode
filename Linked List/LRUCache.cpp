/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. 
Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:
Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:
1 <= capacity <= 3000
0 <= key <= 10^4
0 <= value <= 10^5
At most 2 * 10^5 calls will be made to get and put.
*/

class LRUCache {
public:
    
    map<int,int> data;
    map<int, list<int>::iterator> address;
    list<int> l;
    int cap, size;
    
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }
    
    int get(int key) {
        if(data.find(key) == data.end())
            return -1;
        l.erase(address[key]);
        address.erase(key);
        l.push_front(key);
        address[key] = l.begin();
        return data[key];
    }
    
    void put(int key, int value) {
        if(data.find(key) != data.end()) {
            l.erase(address[key]);
            data.erase(key);
            address.erase(key);
            size--;
        }
        if(size == cap) {
            int k = l.back();
            l.pop_back();
            data.erase(k);
            address.erase(k);
            size--;
        }
        l.push_front(key);
        data[key] = value;
        address[key] = l.begin();
        size++;        
    }
};