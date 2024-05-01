#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;

    vector<pair<int, int>> Graph[n + 1];

    int u, v, w;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;   // Read three integers: u and v represent an edge, and w is the weight of the edge.
        Graph[u].push_back(make_pair(v, w));  // Add a pair (v, w) to the list of neighbors for node u.
        Graph[v].push_back(make_pair(u, w));  // Add a pair (u, w) to the list of neighbors for node v.
    }

    for (int i = 1; i < n + 1; i++)    // Loop through each node from 1 to n.
    {
        cout << "Node: " << i << " -> ";  // Print the current node.
        for (int j = 0; j < Graph[i].size(); j++)    // Loop through its neighbors.
        {
            cout << "(" << Graph[i][j].first << "," << Graph[i][j].second << ")" << " ";  // Print the neighbor nodes in the format (v, w).
        }
        cout << endl;  // Move to the next line for the next node.
    }

    return 0;  // End of the main function and program.
}
