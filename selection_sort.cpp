#include <iostream>
using namespace std;

template <typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;

        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            T temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

template <typename T>
void inputArray(T arr[], int size) {
    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }
}

template <typename T>
void outputArray(const T arr[], int size) {
    cout << "Sorted array:\n";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int intSize;
    cout << "Enter the number of integers: ";
    cin >> intSize;
    int* intArray = new int[intSize];

    inputArray(intArray, intSize);
    selectionSort(intArray, intSize);
    outputArray(intArray, intSize);

    delete[] intArray; 

    int floatSize;
    cout << "Enter the number of floats: ";
    cin >> floatSize;
    float* floatArray = new float[floatSize];

    inputArray(floatArray, floatSize);
    selectionSort(floatArray, floatSize);
    outputArray(floatArray, floatSize);

    delete[] floatArray;

    return 0;
}