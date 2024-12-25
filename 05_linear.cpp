// Program to calculate linear regression

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    // get number of datapoints
    int n;
    cout << "Enter the number of datapoints: ";
    cin >> n;

    // declare vectors for x and y values
    vector<float> x(n), y(n);

    // input for data points
    cout << "Enter x and y values: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x[" << (i + 1) << "] : ";
        cin >> x[i];
        cout << "y[" << (i + 1) << "] : ";
        cin >> y[i];
    }

    // calculate sums
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++)
    {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Calculate slope (m) and intercept (c)
    float m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    float c = (sumY - m * sumX) / n;

    // Display the result with fixed precision
    cout << fixed << setprecision(4);
    cout << "The linear regression equation is: y = " << m << "x + " << c << endl;

    // Predict y for a given value of x
    float xPredict;
    cout << "Enter a value of x to predict y: ";
    cin >> xPredict;

    float yPredict = m * xPredict + c;
    cout << "Predicted y value for x = " << xPredict << " is: " << yPredict << endl;

    return 0;
}