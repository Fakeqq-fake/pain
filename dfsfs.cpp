#include <iostream>
using namespace std;

int main() {
    const int val1 = 10;
    const int* ptr1 = &val1;
    int val2 = 20;
    ptr1 = &val2;


    int val3 = 30;
    int* const ptr2 = &val3;
    *ptr2 = 40;

    const int* const ptr3 = &val1;

    int a = 1, b = 2;
    const int* ptr4 = &a;
    ptr4 = &b;

    const int x = 10;
    int y = 20;
    const int* p = &x;
    p = &y;

    double* dptr = new double;
    *dptr = 3.14;
    cout << *dptr << endl;
    delete dptr;

    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = 3 * (i + 1);
    }

    int max_val = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    delete[] arr;

    int* arr2 = new int[5];
    delete[] arr2;

    int* dyn_arr = new int[5];
    int* temp = dyn_arr;
    for (int i = 0; i < 5; ++i) {
        *temp = i * 2;
        ++temp;
    }

    for (int i = 0; i < 5; ++i) {
        cout << *(dyn_arr + i) << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; ++i) {
        cout << dyn_arr[i] << " " << *(dyn_arr + i) << endl;
    }
    delete[] dyn_arr;

    int var = 100;
    int& ref = var;
    ref = 200;

    auto increment_ptr = [](int* ptr) { ++(*ptr); };
    auto increment_ref = [](int& ref) { ++ref; };

    int num = 5;
    increment_ptr(&num);
    increment_ref(num);

    const int& const_ref = var;

    auto allocate_int = [](int value) -> int* {
        int* ptr = new int;
        *ptr = value;
        return ptr;
    };

    int* heap_int = allocate_int(42);
    cout << *heap_int << endl;
    delete heap_int;

int main() {
    const int val1 = 10;
    const int* ptr1 = &val1;
    int val2 = 20;
    ptr1 = &val2;

    int val3 = 30;
    int* const ptr2 = &val3;
    *ptr2 = 40;

    const int* const ptr3 = &val1;

    const int* ptr4 = &val1;
    ptr4 = &val2;

    const int x = 10;
    int y = 20;
    const int* p = &x;
    p = &y;

    double* dptr = new double;
    *dptr = 3.14;
    cout << "Double value: " << *dptr << endl;
    delete dptr;

    int n = 5;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = 3 * (i + 1);
    }

    int max_val = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    cout << "Max value: " << max_val << endl;

    delete[] arr;

    int* arr2 = new int[5];
    delete[] arr2;  // Правильно: delete[] для массивов

    int* dyn_arr = new int[5];
    int* temp = dyn_arr;
    for (int i = 0; i < 5; ++i) {
        *temp = i * 2;
        ++temp;
    }

    cout << "Array via *(arr + i): ";
    for (int i = 0; i < 5; ++i) {
        cout << *(dyn_arr + i) << " ";
    }
    cout << endl;

    cout << "Equivalence test:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "arr[" << i << "] = " << dyn_arr[i] 
             << ", *(arr + " << i << ") = " << *(dyn_arr + i) << endl;
    }
    delete[] dyn_arr;

    int var = 100;
    int& ref = var;
    ref = 200;
    cout << "Var after ref change: " << var << endl;

    auto increment_ptr = [](int* ptr) { ++(*ptr); };
    auto increment_ref = [](int& ref) { ++ref; };

    int num = 5;
    increment_ptr(&num);
    cout << "After ptr increment: " << num << endl;
    increment_ref(num);
    cout << "After ref increment: " << num << endl;

    const int& const_ref = var;

    auto allocate_int = [](int value) -> int* {
        int* ptr = new int;
        *ptr = value;
        return ptr;
    };

    int* heap_int = allocate_int(42);
    cout << "Dynamically allocated value: " << *heap_int << endl;
    delete heap_int;

    return 0;
}
