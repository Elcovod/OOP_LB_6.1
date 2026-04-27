#include "Task.h"
#include <cmath>

Array processArray(const double* arr, int n) {
    // 1. Створюємо об'єкт Array на основі звичайного масиву
    Array result(n);
    for (int i = 0; i < n; i++) {
        result[i] = arr[i];
    }

    // 2. Шукаємо перше та останнє від'ємне число
    double firstNeg = 0.0;
    double lastNeg = 0.0;
    bool foundFirst = false;

    for (int i = 0; i < n; i++) {
        if (result[i] < 0) {
            if (!foundFirst) {
                firstNeg = result[i];
                foundFirst = true;
            }
            lastNeg = result[i]; // Оновлюється, доки не знайдемо останнє
        }
    }

    // 3. Помножити кожне третє число на подвоєну суму першого і останнього від’ємних чисел.
    double multiplier = 2.0 * (firstNeg + lastNeg);

    // Кожне третє число (це 3-й, 6-й, 9-й елементи... тобто індекси 2, 5, 8...)
    for (int i = 2; i < n; i += 3) {
        result[i] *= multiplier;
    }

    // 4. Обчислюємо загальну суму та середнє арифметичне за абсолютною величиною
    double sum = 0.0;
    double absSum = 0.0;

    for (int i = 0; i < n; i++) {
        sum += result[i];
        absSum += std::abs(result[i]);
    }

    double absAvg = (n > 0) ? (absSum / n) : 0.0;

    // 5. Дописуємо результати в кінець масиву (збільшуємо довжину)
    result.push_back(sum);
    result.push_back(absAvg);

    return result;
}