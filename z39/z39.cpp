/*Характеристикой столбца целочисленной матрицы назовем сумму мо-
дулей его отрицательных нечетных элементов. Переставляя столбцы заданной
матрицы, расположить их в соответствии с ростом характеристик. Найти сумму
элементов в тех столбцах, которые содержат хотя бы один отрицательный элемент.*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <input_check.h>

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "rus");

    int n, m;

    std::cout << "Введите размеры целочисленной матрицы (данные - натуральные числа)";
    
    n = input_check::inputNatural();
    m = input_check::inputNatural();

    int **a = new int*[n];
    int *sum = new int[m];
    bool *haveNeg = new bool[m];
    for (int i = 0; i < n; i++) {
        *(a + i) = new int[m];
    }

    /* for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
            if (a[i][j] < 0) {
                haveNeg[j] = true;
                sum[j] += abs(a[i][j]);
            }
        }
    } */
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 20 - 10;
            if (a[i][j] < 0 && a[i][j] % 2 != 0) {
                haveNeg[j] = true;
                sum[j] += abs(a[i][j]);
            }
        }
    }

    std::cout << "Исходная целочисленная матрица:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    std::cout << "Изначальные характеристики столбцов:\n";
    for (int j = 0; j < m; j++) {
        std::cout << sum[j] << " ";
    }

    std::cout << "\n\n";

    for (int j = 0; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
            if (sum[j] > sum[k]) {
                std::cout << j + 1 << " <-> " << k + 1 << "\n";
                for (int i = 0; i < n; i++) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp; 
                }
                
                int temp = sum[j];
                sum[j] = sum[k];
                sum[k] = temp;
            }
        }
    }

    std::cout << "\n";

    std::cout << "Изменённая матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << a[i][j] << "  ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    std::cout << "Отсортироваанный массив характеристик:\n";
    for (int i = 0; i < m; i++) {
        std::cout << sum[i] << " ";
    }

    std::cout << "\n";

    int sumWithNeg = 0;
    for (int j = 0; j < m; j++) {
        if (haveNeg[j] == true) {
            for (int i = 0; i < n; i++) {
                sumWithNeg += a[i][j];
            }
        }
    }

    std::cout << "Сумма элементов в столбцах с отрицательными элементами:\n" << sumWithNeg;

    delete []a;

    return 0;
}