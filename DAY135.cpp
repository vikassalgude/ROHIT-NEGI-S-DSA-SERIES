class Solution {
  public:
    
    

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            // Found a back edge (cycle)
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    // Step 1: Build adjacency list
    vector<vector<int>> adj(V);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: DFS for each unvisited node
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

};
