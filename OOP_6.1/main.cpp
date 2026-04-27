#include "Array.h"
#include "Task.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Введіть розмір масиву (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Розмір має бути більшим за 0." << endl;
        return 1;
    }

    // Створюємо та заповнюємо звичайний масив випадковими числами [-50; 50]
    double* initialArray = new double[n];
    cout << "Початковий звичайний масив:" << endl;
    for (int i = 0; i < n; i++) {
        initialArray[i] = -50 + rand() % 101;
        cout << initialArray[i] << "  ";
    }
    cout << endl << endl;

    try {
        // Викликаємо робочу функцію
        Array resultArray = processArray(initialArray, n);

        cout << "Результуючий динамічний масив (контейнер Array):" << endl;
        // Використовуємо перевантажений оператор виводу, реалізований у твоєму класі
        cout << resultArray;

        cout << "\n(Останні два елементи — це сума та середнє абсолютне значення відповідно)" << endl;

    }
    catch (const exception& e) {
        cerr << "Виникла помилка: " << e.what() << endl;
    }

    // Очищення пам'яті початкового масиву
    delete[] initialArray;

    return 0;
}