#include<bits/stdc++.h> // Include the standard C++ library for input/output operations and algorithms.

using namespace std; // Using the standard namespace.

int main() // Main function.
{
    int n; // Declare an integer variable 'n'.
    cin >> n; // Input the size of the array 'n'.

    int List[n]; // Declare an array 'List' of size 'n' to store the input elements.

    for(int i = 0; i < n; i++) // Loop to input 'n' elements into the 'List' array.
    {
        cin >> List[i]; // Input each element and store it in the 'List' array.
    }

    int LIS[n]; // Declare an array 'LIS' of size 'n' to store the LIS values for each element.

    for(int i = 0; i < n; i++) // Loop to initialize the 'LIS' array with 1.
    {
        LIS[i] = 1; // Initialize each element of 'LIS' with the default value of 1.
    }

    for(int i = 1; i < n; i++) // Loop to find the LIS for each element.
    {
        for(int j = 0; j < i; j++) // Nested loop to compare current and previous elements.
        {
            if(List[j] < List[i]) // Check if the previous element is smaller than the current one.
            {
                LIS[i] = max(LIS[i], 1 + LIS[j]); // Update the LIS value if the condition is met.
            }
        }
    }

    for(int i = 0; i < n; i++) // Loop to output the LIS values for each element.
    {
        cout << LIS[i] << " "; // Output the LIS value for each element.
    }

    cout << endl; // Move to a new line after printing LIS values.

    int maxi = -1; // Initialize a variable 'maxi' to store the maximum LIS value found.

    for(int i = 0; i < n; i++) // Loop to find the maximum LIS value among all elements.
    {
        if(LIS[i] > maxi) // Check if the current LIS value is greater than the stored maximum.
        {
            maxi = LIS[i]; // Update the maximum value if a larger LIS is found.
        }
    }

    cout << maxi << endl; // Output the maximum LIS value found.

    return 0; // Return 0 to indicate successful program execution.
}
