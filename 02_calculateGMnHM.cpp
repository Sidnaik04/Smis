// Program to calculate Geometric Mean and Harmonic Mean

#include <iostream>
#include <algorithm> //for sorting
#include <cmath>     //for pow

using namespace std;

// Top calculate Geometric Mean
float geometricMean(int arr[], int size)
{
    float product = 1.0; // initial

    // Apply standard formula to understand
    for (int i = 0; i < size; i++)
    {
        product *= arr[i];
    }

    return pow(product, 1.0 / size); // power
}

// Top calculate Harmonic Mean
float harmonicMean(int arr[], int size)
{
    float sum = 0.0; // initial

    // Apply standard formula to understand
    for (int i = 0; i < size; i++)
    {
        sum += 1.0 / arr[i];
    }

    return size / sum;
}

int main()
{

    int choice;

    do
    {
        int size;
        cout << "Enter the size of your data (0 to exit): ";
        cin >> size;

        if (size == 0)
            break;

        int arr[size];
        cout << "Enter the data: ";

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + size);

        cout << endl
             << "Sorted Data: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Choose the option: " << endl;
        cout << "1. Geometric Mean \t 2. Harmonic Mean \t 3. Both \t 0. Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Geometric Mean : " << geometricMean(arr, size) << endl;
            break;
        case 2:
            cout << "Harmonic Mean : " << harmonicMean(arr, size) << endl;
            break;
        case 3:
            cout << "Geometric Mean : " << geometricMean(arr, size) << endl;
            cout << "Harmonic Mean : " << harmonicMean(arr, size) << endl;
            break;
        case 0:
            cout << "Program Exit!!!" << endl;
            break;
        default:
            cout << "Invalid Choice. Try Again " << endl;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}