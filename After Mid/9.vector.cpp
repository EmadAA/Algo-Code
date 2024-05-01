#include <bits/stdc++.h>  // Include a library with common C++ functions and data structures.
using namespace std;      // Use the standard C++ namespace

int main()                // Start of the main function.
{

    vector<int> v;        // Create a vector called 'v' to store integers.
    v.push_back(10);      // Add the value 10 to the end of the vector.
    v.push_back(20);      // Add the value 20 to the end of the vector.
    v.push_back(30);      // Add the value 30 to the end of the vector.
    v.push_back(40);      // Add the value 30 to the end of the vector.
    v.push_back(50);      // Add the value 30 to the end of the vector.

    cout << "Capacity:" << v.capacity() << endl;  // Print the capacity of the vector (initial capacity).

    cout << "size " << v.size() << endl;      // Print the current size of the vector (number of elements).

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";  // Print each element in the vector.
    }
    cout << endl;

    v.pop_back();        // Remove the last element from the vector.

    cout << "Cap:" << v.capacity() << endl;  // Print the capacity of the vector after removing an element.

    cout << "size " << v.size() << endl;      // Print the updated size of the vector.

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";  // Print the remaining elements in the vector.
    }

    return 0;  // End of the main function and program.
}
