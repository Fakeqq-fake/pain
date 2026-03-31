#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    const double EPSILON = 0.001;

    double x1 = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0;
    double new_x1, new_x2, new_x3, new_x4;

    int iteration = 0;
    bool converged = false;

    cout << "Метод простой итерации для системы линейных уравнений" << endl;
    cout << "Точность: " << EPSILON << endl;
    cout << "Итерации:" << endl;

    while (!converged) {
        new_x1 = 0.32 * x2 - 0.23 * x3 + 0.41 * x4 + 0.67;
        new_x2 = 0.18 * x1 + 0.12 * x2 - 0.33 * x3 - 0.88;
        new_x3 = 0.12 * x1 + 0.32 * x2 - 0.05 * x3 + 0.67 * x4 - 0.18;
        new_x4 = 0.05 * x1 - 0.11 * x2 + 0.09 * x3 - 0.12 * x4 + 1.44;

        converged = (abs(new_x1 - x1) < EPSILON) &&
                    (abs(new_x2 - x2) < EPSILON) &&
                    (abs(new_x3 - x3) < EPSILON) &&
                    (abs(new_x4 - x4) < EPSILON);

        x1 = new_x1;
        x2 = new_x2;
        x3 = new_x3;
        x4 = new_x4;

        iteration++;

        if (iteration <= 10) {
            cout << "Итерация " << iteration << ": x1=" << fixed << setprecision(6) << x1
                 << ", x2=" << x2 << ", x3=" << x3 << ", x4=" << x4 << endl;
        }

        if (iteration > 1000) {
            cout << "Предупреждение: превышено максимальное число итераций!" << endl;
            break;
        }
    }

    cout << "\nРешение системы (с точностью " << EPSILON << "):" << endl;
    cout << "x1 = " << fixed << setprecision(6) << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "x4 = " << x4 << endl;
    cout << "Число итераций: " << iteration << endl;

    return 0;
}


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    double a11 = 3.2, a12 = -11.5, a13 = 3.8, b1 = 2.8;
    double a21 = 0.8, a22 = 1.3, a23 = -6.4, b2 = -6.5;
    double a31 = 2.4, a32 = 7.2, a33 = -1.2, b3 = 4.5;

    const double EPSILON = 0.001;

    double x1 = 0.0, x2 = 0.0, x3 = 0.0;
    double new_x1, new_x2, new_x3;

    int iteration = 0;
    bool converged = false;

    cout << "Метод Зейделя для решения системы линейных уравнений" << endl;
    cout << "Точность: " << EPSILON << endl;
    cout << "Итерации:" << endl;

    while (!converged) {
        iteration++;

        new_x1 = (b1 - a12 * x2 - a13 * x3) / a11;
        new_x2 = (b2 - a21 * new_x1 - a23 * x3) / a22; 
        new_x3 = (b3 - a31 * new_x1 - a32 * new_x2) / a33; 

        converged = (abs(new_x1 - x1) < EPSILON) &&
                    (abs(new_x2 - x2) < EPSILON) &&
                    (abs(new_x3 - x3) < EPSILON);

        x1 = new_x1;
        x2 = new_x2;
        x3 = new_x3;

        if (iteration <= 10) {
            cout << "Итерация " << iteration << ": x1=" << fixed << setprecision(6) << x1
                 << ", x2=" << x2 << ", x3=" << x3 << endl;
        }
        if (iteration > 1000) {
            cout << "Предупреждение: превышено максимальное число итераций!" << endl;
            break;
        }
    }
    cout << "\nРешение системы (с точностью " << EPSILON << "):" << endl;
    cout << "x1 = " << fixed << setprecision(6) << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "Число итераций: " << iteration << endl;

    return 0;
}
