#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <algorithm>

using namespace std;

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}


void print(int value) {
    cout << "Целое число: " << value << endl;
}

void print(double value) {
    cout << "Вещественное число: " << value << endl;
}

int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

double maxValue(double a, double b) {
    return (a > b) ? a : b;
}


int square(int x) {
    return x * x;
}

double square(double x) {
    return x * x;
}

int absValue(int x) {
    return (x < 0) ? -x : x;
}

double absValue(double x) {
    return (x < 0) ? -x : x;
}


double average(int a, int b) {
    return static_cast<double>(a + b) / 2;
}

double average(int a, int b, int c) {
    return static_cast<double>(a + b + c) / 3;
}


void printArray(const int arr[], int size) {
    cout << "Одномерный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(const int** arr, int rows, int cols) {
    cout << "Двумерный массив:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int minValue(int a, int b) {
    return (a < b) ? a : b;
}

int minValue(const int arr[], int size) {
    if (size == 0) return 0;
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}


void swapValues(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapValues(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}


double power(double base, int exponent = 2) {
    double result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int sumArray(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

double sumArray(const double arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

int findMax(const int arr[10]) {
    int max = arr[0];
    for (int i = 1; i < 10; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int findMax(const int* arr, int size) {
    if (size == 0) return 0;
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}


int countPositive(const int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) count++;
    }
    return count;
}

int countPositive(const int** arr, int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > 0) count++;
        }
    }
    return count;
}


void print(const int arr[], int size) {
    cout << "Массив целых чисел: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(const double arr[], int size) {
    cout << "Массив вещественных чисел: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


double area(double side) {
    return side * side;
}

double area(double length, double width) {
    return length * width;
}

double area(double radius) {
    return M_PI * radius * radius;
}

int compare(int a, int b) {
    if (a == b) return 0;
    return (a > b) ? 1 : -1;
}

int compare(double a, double b) {
    if (abs(a - b) < 1e-9) return 0;
    return (a > b) ? 1 : -1;
}

int maxIndex(const int arr[], int size) {
    if (size == 0) return -1;
    int maxIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }
    return maxIdx;
}

int minIndex(const int arr[], int size) {
    if (size == 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] < arr[minIdx]) minIdx = i;
    }
    return minIdx;
}

void fillArray(int arr[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

void fillArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}

inline bool isEqual(int a, int b) {
    return a == b;
}

inline bool isEqual(double a, double b) {
    return abs(a - b) < 1e-9; 
}
