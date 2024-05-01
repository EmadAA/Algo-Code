#include <bits/stdc++.h>  // Include a library with common C++ functions and data structures.
using namespace std;      // Use the standard C++ namespace.

int n, e;                 // Declare two integer variables for the number of vertices (n) and edges (e).
int visit[1001];          // Create an array called visit to mark visited nodes.
int graph[1001][1001];    // Create a 2D array to represent the graph (adjacency matrix).

// globally korai memset korra lagbo na arr global korai auto 0 hoi
void Dfs(int start)
{
    cout << start << " ";  // Print the current node.
    visit[start] = 1;      // Mark the current node as visited.

    for (int j = 1; j <= n; j++)    // Loop through all nodes.
    {
        if (graph[start][j] != 0 && visit[j] == 0)
        {
            // If there's a connection between the current node and node 'j' and 'j' hasn't been visited yet.
            Dfs(j);  // Recursively explore node 'j'.
        }
    }
}

int main()
{
    cin >> n >> e;  // Read the number of vertices (n) and edges (e) from the user.

    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        graph[u][v] = 1;  // Set the adjacency matrix to 1 to represent an edge.
        graph[v][u] = 1;  // Ensure the graph is undirected, so set the reverse edge.
    }

    int start_node;
    cout << "Enter the starting Node: ";
    cin >> start_node;  // Ask the user for the starting node for DFS.

    Dfs(start_node);  // Call the DFS function to traverse the graph.

    return 0;  // End of the main function and program.
}
