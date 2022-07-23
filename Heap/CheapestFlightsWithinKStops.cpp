/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:
Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

Example 2:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.

Example 3:
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

Constraints:
1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 10^4
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/


//dist, node, stops
typedef tuple<int,int,int> Pair;

class Graph {
public:
    
    vector<vector<pair<int,int>>> adj;
    int size;
    
    void generateGraph(vector<vector<int>> &input, int n) {
        size = n;
        adj.resize(size);
        
        for(int i = 0 ; i < input.size() ; i++) {
            adj[input[i][0]].push_back({input[i][1], input[i][2]});
        }
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        Graph g;
        g.generateGraph(flights, n);
        
        //min heap
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        
        vector<int> dist(n, INT_MAX);
        vector<int> stops(n, INT_MAX);
        
        dist[src] = 0;
        stops[src] = 0;
        pq.push({0,src,0});
        
        while(!pq.empty()) {
            auto [currDist, currNode, currStops] = pq.top();
            pq.pop();
            if(currNode == dst)
                return currDist;
            if(currStops == k+1)
                continue;
            for(auto &[nextNode, nextPrice] : g.adj[currNode]) {
                int nextDist = currDist + nextPrice;
                int nextStops = currStops + 1;
                if(nextDist < dist[nextNode] || nextStops < stops[nextNode]) {
                    dist[nextNode] = nextDist;
                    stops[nextNode] = nextStops;
                    pq.push({nextDist, nextNode, nextStops});
                }
            }
        }
        
        return -1;
    }
};