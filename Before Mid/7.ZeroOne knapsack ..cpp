#include<bits/stdc++.h>  // Include necessary libraries for input/output.
using namespace std;  // Use the standard C++ namespace.

int main()
{
    int n, m;  // Declare two integer variables for the number of objects (n) and the knapsack capacity (m).
    cin >> n >> m;  // Read the values of n and m from the user.

    int profit[n], weight[n];  // Declare arrays to store profit and weight for each object.

    // Read the profit values for each object.
    for (int i = 0; i < n; i++)
    {
        cin >> profit[i];
    }

    // Read the weight values for each object.
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int V[n + 1][m + 1];  // Create a 2D array to store maximum profit values.

    // Initialize the array with zeros.
    memset(V, 0, sizeof(V));

    // Loop through all objects and knapsack capacities.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j < weight[i - 1])
            {
                V[i][j] = V[i - 1][j];  // If the object can't fit, use the value from the previous row.
            }
            else
            {
                V[i][j] = max(V[i - 1][j], profit[i - 1] + V[i - 1][j - weight[i - 1]]);
                // Calculate the maximum value if the current object is taken or not.
            }
        }
    }

    // Print the calculated values in the 2D array.
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << V[i][j] << " ";
        }
        cout << endl;
    }

    // Find and print the maximum profit achieved.
    cout << "Maximum Profit: " << V[n][m] << endl;

    // Determine and print the selected objects 0 based index okk.
    cout << "Selected objects: ";
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        if (V[i][j] != V[i - 1][j])
        {
            // If selecting the current object increases profit, mark it as selected.
            cout << i - 1 << " ";
            j = j - weight[i - 1];
        }
        i--;
    }
    cout << endl;

    return 0;  // End the program.
}
