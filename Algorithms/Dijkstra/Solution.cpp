// Problem Link : https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1



class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
		

		vector<int>dist(V, INT_MAX);
		
		vector<vector<pair<int,int>>>adj(V);
		for(auto &e : edges) {
		    adj[e[0]].push_back({e[1],e[2]});
		    adj[e[1]].push_back({e[0],e[2]});

		}
		
		dist[src] = 0;
		pq.push({0,src});
		
		while(!pq.empty()) {
		    
		    int mycost = pq.top().first;
		    int mynode = pq.top().second;
		    pq.pop();
		    
            if (mycost > dist[mynode]) continue;   
		    
		    for(auto &it : adj[mynode]) {
		        int connected_node = it.first;
		        int edge_cost = it.second;
		        
		        if(edge_cost+ mycost < dist[connected_node]) {
		            dist[connected_node] = edge_cost + mycost;
		            pq.push({dist[connected_node] , connected_node});
		        }
		    }
		    
		}
		
		return dist;
	}
};
