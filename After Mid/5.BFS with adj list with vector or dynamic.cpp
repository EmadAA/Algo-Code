#include <bits/stdc++.h>  // Include a library with common C++ functions and data structures.
using namespace std;      // Use the standard C++ namespace.

int n, e;                 // Declare two integer variables for the number of vertices (n) and edges (e).
int visit[101];           // Create an array called visit to mark visited nodes.
vector<int> graph[101];    // Create an array of vectors to represent the graph.

void Bfs(int start)
{
    visit[start] = 1;     // Mark the starting node as visited.
    cout << start << " "; // Print the starting node.

    queue<int> Que;       // Create a queue to perform Breadth-First Search.
    Que.push(start);      // Add the starting node to the queue.

    while (!Que.empty())
    {
        int x = Que.front();  // Get the front element of the queue.
        Que.pop();            // Remove the front element from the queue.

        for (int j = 0; j < graph[x].size(); j++)
        {
            int node = graph[x][j];  // Get the neighbors of the current node.

            if (visit[node] == 0)    // If the neighbor has not been visited.
            {
                visit[node] = 1;    // Mark the neighbor as visited.
                cout << node << " ";  // Print the neighbor.
                Que.push(node);      // Add the neighbor to the queue for further exploration.
            }
        }
    }
}

int main()
{
    cin >> n >> e;  // Read the number of vertices (n) and edges (e).

    int u, v;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);  // Create an undirected graph by adding edges.
        graph[v].push_back(u);  // Ensure that the graph is bidirectional.
    }

    int start_node;
    cout << "Enter the starting Node: ";
    cin >> start_node;  // Ask the user for the starting node for BFS.

    Bfs(start_node);     // Call the BFS function to traverse the graph.

    return 0;  // End of the main function and program.
}
