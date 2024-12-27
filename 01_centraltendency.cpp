// Meaure of central tendency => to calcualte mean, mode and median

#include <iostream>
#include <algorithm>

using namespace std;

// To calculate Mean
float mean(int arr[], int size)
{

    int sum = 0; // initial sum
    for (int i = 0; i < size; i++)
    {
        sum += arr[i]; // total
    }

    return (float)sum / size; // total / size
}

// To calculate Median
float median(int arr[], int size)
{
    // for even
    if (size % 2 == 0)
    {
        return (float)(arr[size / 2] + arr[(size / 2) - 1]) / 2;
    }
    // for odd
    else
    {
        return (float)arr[size / 2];
    }
}

// To calculate mode
float mode(int arr[], int size) {
    // Need at least 2 numbers to have a mode
    if (size < 2) {
        return 0;
    }

    int max_count = 1;     // tracks highest frequency seen
    int current_count = 1; // tracks current number's frequency
    int mode_value = arr[0];

    // Count consecutive equal numbers in sorted array
    for (int i = 1; i < size; i++) {  // Start from 1, not 0
        if (arr[i] == arr[i - 1]) {
            current_count++;
            if (current_count > max_count) {  // Update mode if current count is higher
                max_count = current_count;
                mode_value = arr[i];
            }
        } else {
            current_count = 1;  // Reset count when number changes
        }
    }

    // Return 0 if no mode exists (no number appears more than once)
    return (max_count > 1) ? mode_value : 0;
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
        cout << "1. Mean \t 2. Median \t 3. Mode \t 4. All \t 0. Exit" << endl;

        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Mean : " << mean(arr, size) << endl;
            break;
        case 2:
            cout << "Median : " << median(arr, size) << endl;
            break;
        case 3:
            cout << "Mode : " << mode(arr, size) << endl;
            break;
        case 4:
            cout << "Mean : " << mean(arr, size) << endl;
            cout << "Median : " << median(arr, size) << endl;
            cout << "Mode : " << mode(arr, size) << endl;
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