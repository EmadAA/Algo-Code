#include<bits/stdc++.h>  // Include necessary libraries for input/output.
using namespace std;  // Use the standard C++ namespace.

const int infinity = 1e9;  // A very large value representing infinity.

int main()
{
    int n, m;  // Declare two variables to store the number of coin types (n) and the desired total amount (m).
    cin >> n >> m;  // Read values for n and m from the user.

    int coin[n];  // Create an array to store the values of each coin type.

    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];  // Read the values of each coin from the user.
    }

    int coins[n + 1][m + 1];  // Create a 2D array to store the minimum number of coins for different subproblems.

    for (int j = 0; j <= m; j++)
    {
        coins[0][j] = infinity;  // Initialize the first row with infinity since no coins are needed for any amount yet.
    }

    for (int i = 0; i <= n; i++)
    {
        coins[i][0] = 0;  // Initialize the first column with 0 since zero coins are needed to make a total of 0.
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (coin[i - 1] <= j)
            {
                // Calculate the minimum number of coins needed to make change.
                coins[i][j] = min(coins[i - 1][j], 1 + coins[i][j - coin[i - 1]]);
            }
            else
            {
                coins[i][j] = coins[i - 1][j];  // Use the previous value when the coin is too big for the current amount.
            }
        }
    }

    cout << "Minimum number of coins: " << coins[n][m] << endl;  // Print the minimum number of coins needed.

    // Track and print the selected coins.
    cout << "Selected coins: ";
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (coins[i][j] != coins[i - 1][j])
        {
            cout << coin[i - 1] << " ";  // Output the coin used.
            j -= coin[i - 1];  // Update the remaining amount.
        }
        else
        {
            i--;  // Move to the previous row if the coin isn't used.
        }
    }

    return 0;  // End the program.
}
