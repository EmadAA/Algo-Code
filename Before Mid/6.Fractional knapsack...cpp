#include <bits/stdc++.h>
using namespace std;

struct Node  // Define a structure named "Node" to store object information.
{
    int obj;  // An integer field for the object's identifier.
    double pbw;  // A floating-point field for the object's profit-to-weight ratio.
};

bool comparePBW(Node index1, Node index2)  // Create a comparison function to sort objects based on profit-to-weight ratio.
{
    if (index1.pbw > index2.pbw)  // If the profit-to-weight ratio of the first object is greater than the second object's ratio.
    {
        return true;  // Return "true" to indicate that the first object should come before the second in sorting.
    }
    else  // If the first object's ratio is not greater than the second.
    {
        return false;  // Return "false" to indicate that the second object should come before the first in sorting.
    }
}

int main()
{
    int n, m;  // Declare  n and m to store the number of objects and knapsack capacity.
    cin >> n >> m;  // Read values for n and m from the user.

    int profit[n], weight[n];  // Declare two arrays to store profit and weight for each object.

    for (int i = 0; i < n; i++)  // A loop to read the profit values for each object.
    {
        cin >> profit[i];  // Read the profit value for the current object.
    }

    for (int i = 0; i < n; i++)  // A loop to read the weight values for each object.
    {
        cin >> weight[i];  // Read the weight value for the current object.
    }

    Node profitByWeight[n];  // Declare an array of Node structures to store objects and their profit-to-weight ratios.

    for (int i = 0; i < n; i++)  // A loop to calculate profit-to-weight ratios for each object.
    {
        profitByWeight[i].obj = i;  // Set the object's identifier.
        profitByWeight[i].pbw = double(profit[i]) / double(weight[i]);  // Calculate and store the profit-to-weight ratio.
    }

    sort(profitByWeight, profitByWeight + n, comparePBW);  // Sort the objects by their profit-to-weight ratios in descending order.

    double X[n];  // Declare an array to store the selection status of each object.
    memset(X, 0, sizeof(X));  // Initialize the X array with zeros.

    double RW = double(m);  // Store the remaining weight capacity of the knapsack.

    for (int i = 0; i < n; i++)  // A loop to select objects for the knapsack.
    {
        if (RW > 0)  // If there is remaining weight capacity in the knapsack.
        {
            if (RW >= weight[profitByWeight[i].obj])  // If the knapsack can hold the entire object.
            {
                RW = RW - weight[profitByWeight[i].obj];  // Reduce the remaining weight capacity.
                X[profitByWeight[i].obj] = 1;  // Set the selection status of the object to 1 (selected).
            }
            else  // If the knapsack cannot hold the entire object.
            {
                X[profitByWeight[i].obj] = RW / weight[profitByWeight[i].obj];  // Set the selection status based on the fraction of the object taken.
                RW = 0;  // Set remaining weight capacity to 0, indicating that the knapsack is full.
            }
        }
    }

    double maxprofit = 0;  // Declare a variable to store the maximum profit.

    for (int i = 0; i < n; i++)  // A loop to calculate the maximum profit.
    {
        maxprofit = maxprofit + X[i] * double(profit[i]);  // Calculate the total profit considering the selected objects.
    }

    cout << "Total Maximum Profit: " << maxprofit << endl;  // Print the maximum profit achieved by the knapsack.

    // Print the selected objects 0 based index okk.
    cout << "Selected objects: ";
    for (int i = 0; i < n; i++)  // A loop to check and print the indices of selected objects.
    {
        if (X[i] > 0)  // If the object is selected (X[i] is greater than 0).
        {
            cout << i << " ";  // Print the index of the selected object.
        }
    }
    cout << endl;  // Print a newline character.

    return 0;  // Return 0 to indicate successful program execution.
}
