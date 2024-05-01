#include <bits/stdc++.h>

using namespace std;

int Visit[100];       // Declare an array to keep track of visited nodes.

int Graph[101][101];        // Declare a 2D array for the graph representation.

int n , e ;

void Bfs(int Start)
{
    Visit[Start] = 1;
    cout << Start << " ";

    queue<int> Que;
    Que.push(Start);        // Add the starting node to the queue.

    while (!Que.empty())    // Perform BFS while the queue is not empty.
    {
        int x = Que.front();         // Get the front element of the queue.
        Que.pop();                  // Remove the front element from the queue.

        for (int j = 1; j <= n; j++)   // Iterate through all nodes (j) in the graph.
        {
            if (Graph[x][j] != 0 && Visit[j] == 0)  // Check if there is an edge between node x and node j, and
                                                      //  if node j has not been visited.
            {
                Visit[j] = 1;       // Mark node j as visited.
                cout << j << " ";   // Print node j.

                Que.push(j);        // Add node j to the queue for further exploration.
            }
        }
    }
}
int main()
{

    cin >> n >> e;  // Read the number of nodes (n) and edges (e) from the user.

    int u, v;   // Read the edge connections and build the graph.
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v;
        Graph[u][v] = 1;    // Mark the presence of an edge between nodes u and v.
        Graph[v][u] = 1;
    }
    int Start_Node; // Declare a variable to store the starting node for BFS.
    cout << "Choose your start Node: ";
    cin >> Start_Node;

    Bfs(Start_Node);    // Call the BFS function with the chosen starting node.

    return 0;
}
