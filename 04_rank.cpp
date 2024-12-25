// program to calculate charles spearmen's rank correlation

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate ranks of array elements
vector<float> rankArray(const vector<float> &array)
{
    int n = array.size();

    vector<float> ranks(n);
    vector<float> sortedArray = array;
    // sort array
    sort(sortedArray.begin(), sortedArray.end());

    for (int i = 0; i < n; i++)
    {
        // Find position of array[i] in sorted array
        auto it = find(sortedArray.begin(), sortedArray.end(), array[i]);
        ranks[i] = distance(sortedArray.begin(), it) + 1;
    }

    return ranks;
}

// Function to calculate Spearman's Rank Correlation
float calculateSpearmanRankCorrelation(const vector<float> &rankX, const vector<float> &rankY)
{
    int n = rankX.size();

    float sumOfSqaureDifference = 0.0;

    for (int i = 0; i < n; i++)
    {
        float difference = rankX[i] - rankY[i];
        sumOfSqaureDifference += difference * difference;
    }

    // formula
    return 1 - (6 * sumOfSqaureDifference) / (n * (n * n - 1));
}

int main()
{
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    // datapoints value
    vector<float> x(n), y(n);

    cout << "Enter values for X: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "X[" << (i + 1) << "] : ";
        cin >> x[i];
    }

    cout << "Enter values for Y: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Y[" << (i + 1) << "] : ";
        cin >> y[i];
    }

    // rank of x and y
    vector<float> rankX = rankArray(x);
    vector<float> rankY = rankArray(y);

    float spearmanCorrelation = calculateSpearmanRankCorrelation(rankX, rankY);

    cout << "Spearman's Rank Correlation Coefficient: " << spearmanCorrelation << endl;

    return 0;
}