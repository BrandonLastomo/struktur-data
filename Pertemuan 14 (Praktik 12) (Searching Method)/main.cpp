#include <iostream>
using namespace std;

// Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++){
        if (arr[i] == key){
            cout << "Is " << arr[i] << " in index " << i << "  the target? " << (arr[i] == key) << endl;
            return i;
        }
        cout << "Is " << arr[i] << " in index " << i << " the target? " << (arr[i] == key) << endl;
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key){
            cout << "low = " << low << " | mid = " << mid << " | high = " << high << endl;
            cout << "Is " << arr[mid] << " in index " << mid << "  the target? " << (arr[mid] == key) << endl;
            return mid;
        } else if (arr[mid] < key){
            cout << "low = " << low << " | mid = " << mid << " | high = " << high << endl;
            cout << "Is " << arr[mid] << " in index " << mid << "  the target? " << (arr[mid] == key) << endl;
            low = mid + 1;
        } else {
            cout << "low = " << low << " | mid = " << mid << " | high = " << high << endl;
            cout << "Is " << arr[mid] << " in index " << mid << "  the target? " << (arr[mid] == key) << endl;
            high = mid - 1;
        }
    }
    return -1;
}

// Interpolation Search
int interpolationSearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        if (low == high) {
            if (arr[low] == key){
                cout << "Is " << arr[low] << " in index " << low << "  the target? " << (arr[low] == key) << endl;
                return low;
            }
            return -1;
        }
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key){
            cout << "pos = " << pos << " | low = " << low << " | high = " << high << endl;
            cout << "Is " << arr[pos] << " in index " << pos << "  the target? " << (arr[pos] == key) << endl;
            return pos;
        } else if (arr[pos] < key) {
            cout << "pos = " << pos << " | low = " << low << " | high = " << high << endl;
            cout << "Is " << arr[pos] << " in index " << pos << "  the target? " << (arr[pos] == key) << endl;
            low = pos + 1;
        } else {
            cout << "pos = " << pos << " | low = " << low << " | high = " << high << endl;
            cout << "Is " << arr[pos] << " in index " << pos << "  the target? " << (arr[pos] == key) << endl;
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    int num[] = {5, 10, 15, 20, 25, 30, 35};
    int n = sizeof(num)/sizeof(num[0]);
    int target = 25;
    int choice, result;

    do {
        // Display array
        cout << "array in search: ";
        for (int i = 0; i < n; i++) {
            cout << num[i] << " ";
        }
        cout << endl;
        cout << "Number being searched: " << target;
        cout << endl;
        cout << "\nChoose Search Method:\n";
        cout << "1. Linear Search\n";
        cout << "2. Binary Search\n";
        cout << "3. Interpolation Search\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                result = linearSearch(num, n, target);
                break;
            case 2:
                result = binarySearch(num, n, target);
                break;
            case 3:
                result = interpolationSearch(num, n, target);
                break;
            case 4:
                cout << "Thanks" << endl;
                break;
            default:
                cout << "Invalid choice.\n";
                return 1;
        }
        if (result != -1){
            cout << target << " found at index: " << result << endl << endl;
        } else {
            cout << target << " not found in the array." << endl << endl;
        }
    } while (choice != 4);

    return 0;
}
