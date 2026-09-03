#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Rus");

    int age, experience;
    cout << "Введите возраст: ";
    cin >> age;
    cout << "Введите стаж вождения (в годах): ";
    cin >> experience;

    if (age < 18) {
        cout << "Доступ запрещен." << endl;
    }
    else if (experience < 3) {
        cout << "Доступ разрешен, но тариф повышенный." << endl;
    }
    else {
        cout << "Доступ разрешен, стандартный тариф." << endl;
    }

    double a, b;
    char op;
    cout << "Введите первое число: ";
    cin >> a;
    cout << "Введите второе число: ";
    cin >> b;
    cout << "Введите операцию (+, -, *, /): ";
    cin >> op;

    switch (op) {
    case '+':
        cout << "Результат: " << a + b << endl;
        break;
    case '-':
        cout << "Результат: " << a - b << endl;
        break;
    case '*':
        cout << "Результат: " << a * b << endl;
        break;
    case '/':
        if (b == 0) {
            cout << "Ошибка: деление на ноль!" << endl;
        }
        else {
            cout << "Результат: " << a / b << endl;
        }
        break;
    default:
        cout << "Ошибка: неверный символ операции!" << endl;
    }


    int sum = 0;
    for (int i = 1; i <= 100; i += 2) {
        sum += i;
    }
    cout << "Сумма нечётных чисел от 1 до 100: " << sum << endl;

    int num, count = 0;
    cout << "Введите числа (0 — для завершения):" << endl;
    while (cin >> num && num != 0) {
        count++;
    }
    cout << "Введено чисел (без нуля): " << count << endl;

    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 50 + 1;
    }

    cout << "Массив: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int maxVal = arr[0], maxIdx = 0;
    for (int i = 1; i < 10; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
            maxIdx = i;
        }
    }
    cout << "Максимальный элемент: " << maxVal
        << ", индекс: " << maxIdx << endl;

    int x = 5, y = 10;
    int* px = &x;
    int* py = &y;

    cout << "До обмена: a = " << x << ", b = " << y << endl;

    int temp = *px;
    *px = *py;
    *py = temp;

    cout << "После обмена: a = " << x << ", b = " << y << endl;

    int n;
    cout << "Введите число для проверки: ";
    cin >> n;

    if (isPrime(n)) {
        cout << "Число " << n << " является простым." << endl;
    }
    else {
        cout << "Число " << n << " является составным." << endl;
    }

    return 0;
}
