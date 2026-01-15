#include <iostream>

template<typename T>
T square(T value) {
    return value * value;
}

template<typename T>
T max_value(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
void print_value(const T& value) {
    std::cout << value << std::endl;
}

template<typename T>
void swap_values(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min_value(T a, T b) {
    return (a < b) ? a : b;
}

template<typename T, size_t N>
void print_array(const T(&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T, size_t N>
size_t count_elements(const T(&)[N]) {
    return N;
}

template<typename T, size_t N>
T sum_array(const T(&arr)[N]) {
    T sum = T();
    for (size_t i = 0; i < N; ++i) {
        sum += arr[i];
    }
    return sum;
}

template<typename T, size_t N>
int find_element(const T(&arr)[N], const T& target) {
    for (size_t i = 0; i < N; ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

template<typename T>
bool are_equal(const T& a, const T& b) {
    return a == b;
}

template<typename T, size_t N>
T min_array_element(const T(&arr)[N]) {
    T min_val = arr[0];
    for (size_t i = 1; i < N; ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

template<typename T, size_t N>
size_t count_positive(const T(&arr)[N]) {
    size_t count = 0;
    for (size_t i = 0; i < N; ++i) {
        if (arr[i] > T()) {
            ++count;
        }
    }
    return count;
}

template<typename T, size_t N>
void bubble_sort(T(&arr)[N]) {
    for (size_t i = 0; i < N - 1; ++i) {
        for (size_t j = 0; j < N - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap_values(arr[j], arr[j + 1]);
            }
        }
    }
}

template<typename T, size_t N>
void copy_array(const T(&src)[N], T(&dest)[N]) {
    for (size_t i = 0; i < N; ++i) {
        dest[i] = src[i];
    }
}

int main() {
    int arr_int[] = { 3, -1, 4, 0, 2 };
    int arr_int_copy[5];

    print_value(square(4));
    print_value(max_value(5, 8));
    print_value(min_value(5, 8));
    print_array(arr_int);
    print_value(count_elements(arr_int));
    print_value(sum_array(arr_int));
    print_value(find_element(arr_int, 4));
    print_value(are_equal(3, 3));
    print_value(min_array_element(arr_int));
    print_value(count_positive(arr_int));
    bubble_sort(arr_int);
    print_array(arr_int);
    copy_array(arr_int, arr_int_copy);
    print_array(arr_int_copy);

    double arr_double[] = { 2.5, -1.3, 0.0, 4.7 };
    double arr_double_copy[4];

    print_value(square(2.0));
    print_value(max_value(1.5, 3.2));
    print_value(min_value(1.5, 3.2));
    print_array(arr_double);
    print_value(count_elements(arr_double));
    print_value(sum_array(arr_double));
    print_value(find_element(arr_double, 0.0));
    print_value(are_equal(2.5, 2.5));
    print_value(min_array_element(arr_double));
    print_value(count_positive(arr_double));
    bubble_sort(arr_double);
    print_array(arr_double);

    return 0;
}
