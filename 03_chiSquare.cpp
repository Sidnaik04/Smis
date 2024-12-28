#include <iostream>
#include <iomanip>
using namespace std;

// Calculate expected frequency
float calcExpected(float colSum, float rowSum, float grandTotal)
{
    return (colSum * rowSum) / grandTotal;
}

// Calculate chi-square value
float chiSquareTest(const float observed[], const float expected[], int size)
{
    float chiSquare = 0.0;
    for (int i = 0; i < size; ++i)
    {
        if (expected[i] <= 0) 
        {
            cout << "Error: Expected frequency cannot be zero or negative." << endl;
            return -1;
        }
        //formula
        float difference = observed[i] - expected[i];
        chiSquare += (difference * difference) / expected[i];
    }
    return chiSquare;
}

int main()
{
    int numRows, numCols;
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numCols;

    int grandTotal;
    cout << "Enter the grand total: ";
    cin >> grandTotal;

    float rowSums[numRows], colSums[numCols];
    cout << "Enter the row sums: ";
    for (int i = 0; i < numRows; ++i)
        cin >> rowSums[i];

    cout << "Enter the column sums: ";
    for (int i = 0; i < numCols; ++i)
        cin >> colSums[i];

    int size = numRows * numCols;
    float observed[size], expected[size];

    cout << "Enter the observed frequencies: ";
    for (int i = 0; i < size; ++i)
        cin >> observed[i];

    // Calculate expected frequencies
    for (int i = 0, index = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            expected[index] = calcExpected(colSums[j], rowSums[i], grandTotal);
            cout << "Expected[" << index << "] = " << expected[index] << endl; // Debug print
            ++index;
        }
    }

    // Compute chi-square value
    float result = chiSquareTest(observed, expected, size);

    if (result >= 0)
        cout << "Chi-square value: " << fixed << setprecision(2) << result << endl;
    else
        cout << "Error in calculation" << endl;

    return 0;
}