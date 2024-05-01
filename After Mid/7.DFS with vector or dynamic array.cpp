#include <bits/stdc++.h>  // Include a library with common C++ functions and data structures.
using namespace std;      // Use the standard C++ namespace.

int n, e;                 // Declare two integer variables for the number of vertices (n) and edges (e).

vector<int> graph[101];   // Create an array of vectors to represent the graph.
int visit[101];           // Create an array called visit to mark visited nodes.

void Dfs(int start)
{
    cout << start << " ";  // Print the current node.
    visit[start] = 1;      // Mark the current node as visited.

    for (int j = 0; j < graph[start].size(); j++)
    {
        // Loop through neighbors of the current node.
        int node = graph[start][j];  // Get the neighbor node.

        if (visit[node] == 0)
        {
            Dfs(node);  // Recursively explore unvisited neighbor nodes.
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
        graph[u].push_back(v);  // Add v to the list of neighbors for node u.
        graph[v].push_back(u);  // Ensure the graph is undirected, so add u to the list of neighbors for node v.
    }

    int start_node;
    cout << "Enter the starting Node: ";
    cin >> start_node;  // Ask the user for the starting node for DFS.

    Dfs(start_node);  // Call the DFS function to traverse the graph.

    return 0;  // End of the main function and program.
}
