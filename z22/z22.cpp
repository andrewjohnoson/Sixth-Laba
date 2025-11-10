#include <iostream>
#include <cstdlib>
#include <ctime>
#include <input_check.h>

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int n;

    std::cout << "Введите размер массива n (натуральное число): ";
    
    n = input_check::inputNatural();

    float *a = new float[n];
    
    /*
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    } */

    for (int i = 0; i < n; i++) {
        *(a + i) = ((float) rand() / (RAND_MAX + 1.0)) * 40 - 20;
    }

    std::cout << "Получившийся массив:\n";
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    
    std::cout << "\n";

    //поиск суммы элементов с четными номерами
    float eSum = 0;
    for (int i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {
            eSum += *(a + i);
        }
    }

    std::cout << "Сумма элементов с чётными номерами: " << eSum << "\n";

    //поиск произведения элементов массива, расположенных между первым и
    //последним положительными элементами.
    int firstPos = 0, lastPos = n - 1;
    bool havePos = true, haveOnePos = true;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            firstPos = i;
            break;
        }
    }

    if (firstPos == 0 && a[firstPos] < 0) {
        havePos = false;
    } else {
        for (int i = n - 1; i > firstPos; i--) {
            if (a[i] > 0) {
                lastPos = i;
                haveOnePos = false;
                break;
            }
        }
    }

    float mult = 1.0;

    if (havePos && haveOnePos) {
        mult = a[firstPos];
    } else {
        for (int i = firstPos + 1; i < lastPos && havePos; i++) {
            mult *= a[i];
        }
    }

    if (havePos) {
        std::cout << "Произведение элементов между " << firstPos + 1 << " и " << lastPos + 1 << " элементам равна: " << mult;
    } else {
        std::cout << "Нету положительных чисел.";
    }
    
    delete []a;
    return 0;
}