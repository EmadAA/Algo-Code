#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int Graph[n+1][n+1];

    memset(Graph, 0, sizeof(Graph));

    int u, v, w;
    for (int i = 1; i < e+1; i++)
    {
        cin >> u >> v >> w;

        Graph[u][v] = w;
        Graph[v][u] = w;
    }

    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
