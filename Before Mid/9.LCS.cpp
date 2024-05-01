// Include necessary libraries
#include <bits/stdc++.h>
using namespace std;
    string str1, str2;

int main()
{
    string str1, str2;
    cin>>str2>>str1;



    // Get the lengths of the two strings
    int n = str1.size();
    int m = str2.size();

    // Create a 2D array for dynamic programming to find LCS
    int lcs[n + 1][m + 1];

    // Initialize the array with zeros
    memset(lcs, 0, sizeof(lcs));

    // Fill the dynamic programming array
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                // If characters match, add 1 to the previous diagonal value
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                // If characters don't match, take the maximum of the top and left values
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    // Display the dynamic programming array
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << lcs[i][j] << " ";
        }
        cout << endl;
    }

    // Initialize indices for backtracking
    int i = n, j = m;

    // Initialize an empty string to store the LCS
    string lcs_string;

    // Backtrack to find the LCS string
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            // If characters match, add the character to the LCS
            lcs_string = str1[i - 1] + lcs_string;
            i--;
            j--;
        }
        else if (lcs[i - 1][j] > lcs[i][j - 1])
        {
            // Move to the direction with a higher LCS value
            i--;
        }
        else
        {
            j--;
        }
    }

    // Display an empty line for clarity
    cout << endl;

    // Display the length of the Longest Common Subsequence
    cout << "Longest Common Subsequence Length: " << lcs[n][m] << endl;

    // Display the Longest Common Subsequence itself
    cout << "Longest Common Subsequence: " << lcs_string << endl;

    return 0;
}
