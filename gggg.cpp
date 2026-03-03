/*
1.
 Объявление и определение функции. Прототип функции
Объявление (прототип) — сообщает компилятору имя функции, типы аргументов и возвращаемый тип:

 int add(int a, int b) {
    return a + b;
} 
2.
 Возврат значения с использованием return
 Оператор return завершает выполнение функции и возвращает значение:

 int square(int x) {
    return x * x; // возвращает квадрат числа
}
3.
Аргументы по умолчанию и их применение
Аргументы по умолчанию задаются в прототипе функции:

void printMessage(std::string msg, int times = 1);

4.
Локальные и глобальные переменные. Классы памяти

Локальные — объявлены внутри функции, существуют только во время её выполнения.
Глобальные — объявлены вне функций, доступны везде в файле.

Классы памяти:
auto — автоматическая переменная (по умолчанию для локальных);
static — сохраняет значение между вызовами функции;
extern — указывает, что переменная определена в другом файле;
register — рекомендация компилятору поместить переменную в регистр процессора.


5. Хвостовой возвращаемый тип функций и decltype
Используется, когда тип возвращаемого значения зависит от типов параметров:

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}

Шаблоны функций и перегрузка
1. Понятие шаблона функции. Синтаксис объявления

Шаблон функции позволяет писать код, работающий с разными типами данных:

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

2. Ключевые слова class и typename
В шаблонах взаимозаменяемы:

template<class T>    // эквивалентно
template<typename T> // этому


3. Отличия обычной функции и шаблонной функции
Обычная функция работает с фиксированными типами.
Шаблонная функция генерирует версии для разных типов при компиляции.

template<typename T>
T Max(T a, T b) { return (a > b) ? a : b; }

template<typename T>
T Min(T a, T b) { return (a < b) ? a : b; }

template<typename T>
void Sort(T arr[], int size) {  реализация сортировки  }

5. Перегрузка функций и перегрузка шаблонных функций
Перегрузка позволяет иметь несколько функций с одним именем :

void print(int x);      // версия для int
void print(double x);   // версия для double
template<typename T>  // шаблонная версия
void print(T x); 

*/

#include <iostream>

// Задание 1: Шаблонная функция Max
template<typename T>
T Max(T a, T b) {
    return (a > b) ? a : b;
}

// Задание 2: Функция с аргументами по умолчанию
double rectangleArea(double width, double height = 0) {
    if (height == 0) {
        height = width; // если height не задан, считаем квадрат
    }
    return width * height;
}

// Задание 3: Функция с хвостовым возвращаемым типом и decltype
template<typename T, typename U>
auto sum(T a, U b) -> decltype(a + b) {
    return a + b;
}

int main() {
    std::cout << "Task 1: Template Function Max\n";
    // Тестирование Max с целыми числами
    std::cout << "Max(5, 10) = " << Max(5, 10) << std::endl;
    std::cout << "Max(-3, -1) = " << Max(-3, -1) << std::endl;

    // Тестирование Max с символами
    std::cout << "Max('a', 'z') = " << Max('a', 'z') << std::endl;
    std::cout << "Max('X', 'A') = " << Max('X', 'A') << std::endl;

    std::cout << "\nTask 2: Function with default arguments\n";
    // Вызов для прямоугольника
    std::cout << "Rectangle area 5x3: "
        << rectangleArea(5, 3) << std::endl;

    // Вызов для квадрата (один аргумент)
    std::cout << "Square area 4x4: "
        << rectangleArea(4) << std::endl;

    // Ещё один пример квадрата
    std::cout << "Square area 7x7: "
        << rectangleArea(7) << std::endl;

    std::cout << "\n Task 3: The sum function with decltype \n";
    // Тестирование sum с разными типами
    std::cout << "sum(5, 3) = " << sum(5, 3) << std::endl;           // int + int
    std::cout << "sum(2.5, 1.7) = " << sum(2.5, 1.7) << std::endl; // double + double
    std::cout << "sum(10, 2.5) = " << sum(10, 2.5) << std::endl;     // int + double
    std::cout << "sum(3L, 4) = " << sum(3L, 4) << std::endl;         // long + int

    return 0;
}
