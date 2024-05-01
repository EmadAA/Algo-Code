#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, e;
    cin >> n >> e;
    vector<int> Graph[n + 1];
    int u, v;
    for (int i = 1; i <= e; i++)    // Loop from 1 to e for reading edge connections.
    {
        cin >> u >> v;
        Graph[u].push_back(v);  // Add v to the list of neighbors for node u.
        Graph[v].push_back(u);  // Add u to the list of neighbors for node v.
    }

    for (int i = 1; i < n + 1; i++)    // Loop through each node from 1 to n.
    {
        cout << "Node: " << i << " -> ";  // Print the current node.
        for (int j = 0; j < Graph[i].size(); j++)    // Loop through its neighbors.
        {
            cout << Graph[i][j] << " ";  // Print the neighbor nodes.
        }
        cout << endl;
    }

    return 0;
}
