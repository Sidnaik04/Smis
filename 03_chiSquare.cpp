// Program for chi-sqaure test

#include <iostream>
using namespace std;

// to calculated expected frequency -> formula
float calcExpected(float colSum, float rowSum, float grandTotal)
{
    return (colSum * rowSum) / grandTotal;
}

// to calculate chisqaure -> formula
float chiSquareTest(const float observerd[], const float expected[], int size)
{
    float chiSqaure = 0.0;

    for (int i = 0; i < size; ++i)
    {
        if (expected[i] == 0)
        {
            cout << "Expected frequency cannot be zero" << endl;
            return -1;
        }
        float difference = observerd[i] - expected[i];
        chiSqaure += (difference * difference) / expected[i];
    }

    return chiSqaure;
}

int main()
{

    // number of rows and columns of table
    int numRows, numCols;
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numCols;

    // grand total of table
    int grandTotal;
    cout << "Enter the grand total: ";
    cin >> grandTotal;

    // individual row sum and column sum
    int rowSums[numRows], colSums[numCols];
    cout << "Enter the row sums: ";
    for (int &rowSum : rowSums)
    {
        cin >> rowSum;
    }

    cout << "Enter the column sums: ";
    for (int &colSum : colSums)
    {
        cin >> colSum;
    }

    // size of table
    int size = numRows * numCols;
    float observed[size], expected[size];

    // enter observed frequency from table
    cout << "Enter the observed frequencies: ";
    for (float &obs : observed)
    {
        cin >> obs;
    }

    // expected frequency
    for (int i = 0, index = 0; i < numRows; ++i)
    {
        for (int j = 0; j < numCols; ++j)
        {
            expected[index++] = calcExpected(colSums[j], rowSums[i], grandTotal);
        }
    }

    // result
    float chiSquareValue = chiSquareTest(observed, expected, size);
    if (chiSquareValue >= 0)
    {
        cout << "Chi-square Value: " << chiSquareValue << endl;
    }
    else
    {
        cout << "Error in calculation" << endl;
    }

    return 0;
}