#include <bits/stdc++.h>  // Include necessary libraries

using namespace std;  // Use the standard namespace

int n, e;  // Declare variables for the number of nodes and edges
int visit[101];  // Array to mark visited nodes
vector<int> graph[101];  // Adjacency list representation of the graph

void Dfs(int start)  // DFS function declaration
{
    visit[start] = 1;  // Mark the starting node as visited
    cout << start << " ";  // Print the starting node
    stack<int> Sta;  // Use stack for DFS
    Sta.push(start);  // Push the starting node onto the stack

    while (!Sta.empty())  // While the stack is not empty
    {
        int x = Sta.top();  // Get the top element of the stack
        Sta.pop();  // Remove the top element from the stack

        for (int j = 0; j < graph[x].size(); j++)  // Iterate through neighbors
        {
            int node = graph[x][j];  // Get the neighbor of the current node

            if (visit[node] == 0)  // If the neighbor has not been visited
            {
                visit[node] = 1;  // Mark the neighbor as visited
                cout << node << " ";  // Print the neighbor
                Sta.push(node);  // Add the neighbor to the stack for further exploration
            }
        }
    }
}

int main()  // Main function
{
    cin >> n >> e;  // Input the number of nodes and edges

    int u, v;
    for (int i = 1; i <= e; i++)  // Input the edges and build the adjacency list
    {
        cin >> u >> v;
        graph[u].push_back(v);  // Add edge from u to v
        graph[v].push_back(u);  // Add edge from v to u (undirected graph)
    }

    int start_node;
    cout << "Enter the starting Node: ";
    cin >> start_node;  // Input the starting node for DFS

    Dfs(start_node);  // Call the DFS function to traverse the graph using a stack

    return 0;  // Return 0 to indicate successful completion
}
