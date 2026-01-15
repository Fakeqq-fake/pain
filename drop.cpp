
#include <iostream>
#include <cmath>

inline int sumindices(const int arr[], int idx1, int idx2) {
    return arr[idx1] + arr[idx2];
}

inline int rangeoffive(const int arr[5]) {
    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; i < 5; ++i) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal - minVal;
}

inline bool areequalindices(const int arr[], int idx1, int idx2) {
    return arr[idx1] == arr[idx2];
}

inline int absvalue(int x) {
    return (x < 0) ? -x : x;
}

inline double absvalue(double x) {
    return (x < 0.0) ? -x : x;
}

inline double maxthree(double a, double b, double c) {
    double maxVal = a;
    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;
    return maxVal;
}

inline double squarearea(double side) {
    return side * side;
}

inline bool isrange(double value, double low, double high) {
    return (value >= low) && (value <= high);
}

inline int diagonalsum2x2(const int matrix[2][2]) {
    return matrix[0][0] + matrix[1][1];
}


inline long long sumarray(const int arr[], int size) {
    long long total = 0;
    for (int i = 0; i < size; ++i) {
        total += arr[i];
    }
    return total;
}

int main() {


    int arr1[] = { 1, 2, 3, 4, 5 };
    std::cout << "sumindices: " << sumindices(arr1, 1, 3) << '\n';

    int arr2[5] = { 10, 3, 8, 1, 7 };
    std::cout << "rangeoffive: " << rangeoffive(arr2) << '\n';  

    std::cout << "areequalindices: " << areequalindices(arr1, 0, 4) << '\n';

    std::cout << "absvalue(int): " << absvalue(-7) << '\n';

    std::cout << "absvalue(double): " << absvalue(-3.14) << '\n';

    std::cout << "maxthree: " << maxthree(1.5, 2.7, 2.1) << '\n';

    std::cout << "squarearea: " << squarearea(4.0) << '\n';

    std::cout << "isrange: " << isrange(5.5, 1.0, 10.0) << '\n';

    int matrix[2][2] = { {1, 2}, {3, 4} };
    std::cout << "diagonalsum2x2: " << diagonalsum2x2(matrix) << '\n';

    int arr3[] = { 1, 2, 3, 4, 5 };
    std::cout << "sumarray: " << sumarray(arr3, 5) << '\n';

    return 0;
}
