#include <iostream>
using namespace std;

void displayAddresses(int **arr, int rows, int cols) {
    cout << "\nAddresses of each element:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << &arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int **arr = new int*[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];

    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nOriginal Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    int delRow;
    cout << "\nEnter row index to delete (0-based): ";
    cin >> delRow;

    if (delRow >= 0 && delRow < rows) {
        for (int i = delRow; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                arr[i][j] = arr[i + 1][j];
            }
        }
        rows--;
    } else {
        cout << "Invalid row index.\n";
    }
    cout << "\nArray after deleting row " << delRow << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    
    displayAddresses(arr, rows, cols);
    for (int i = 0; i < rows; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

