#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-8

// Прототипы функций
int sle(double **matrix, int n, int m, double *roots);
int input(double **matrix, int n, int m);
void output_roots(const double *roots, int n);

// Главная функция
int main() {
    double **matrix;
    int n, m;

    // Ввод размеров матрицы
    if (scanf("%d%d", &n, &m) != 2 || n < 1 || m != n + 1) {
        printf("n/a");
        return 0;
    }

    // Выделение памяти под матрицу
    matrix = malloc(n * sizeof(double *) + n * (m * sizeof(double)));
    if (!matrix) {
        printf("n/a");
        return 0;
    }
    double *p = (double *)(matrix + n);
    for (int i = 0; i < n; i++) {
        matrix[i] = p + i * m;
    }

    // Ввод матрицы
    if (!input(matrix, n, m)) {
        free(matrix);
        return 0;
    }

    // Выделение памяти под массив корней
    double *roots = (double *)malloc(n * sizeof(double));
    if (!roots) {
        printf("n/a");
        free(matrix);
        return 0;
    }

    // Решение СЛАУ
    if (!sle(matrix, n, m, roots)) {
        printf("n/a");
        free(matrix);
        free(roots);
        return 0;
    }

    // Вывод корней и освобождение памяти
    output_roots(roots, n);
    free(matrix);
    free(roots);

    return 0;
}

// Чтение матрицы из stdin
int input(double **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                printf("n/a");
                return 0;
            }
        }
    }
    return 1;
}

// Решение СЛАУ методом Гаусса
int sle(double **matrix, int n, int m, double *roots) {
    // Прямой ход
    for (int i = 0; i < n; i++) {
        // Проверка возможности деления
        if (fabs(matrix[i][i]) < EPSILON) {
            int found = 0;
            for (int k = i + 1; k < n; k++) {
                if (fabs(matrix[k][i]) > EPSILON) {
                    // Меняем строки местами
                    double *temp = matrix[i];
                    matrix[i] = matrix[k];
                    matrix[k] = temp;
                    found = 1;
                    break;
                }
            }
            if (!found) // Если нельзя найти ненулевой элемент
                return 0;
        }

        // Приведение матрицы к треугольному виду
        for (int k = i + 1; k < n; k++) {
            double factor = matrix[k][i] / matrix[i][i];
            for (int j = i; j < m; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Обратный ход
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < n; j++) {
            sum += matrix[i][j] * roots[j];
        }
        roots[i] = (matrix[i][m - 1] - sum) / matrix[i][i];
    }

    return 1;
}

// Вывод решений
void output_roots(const double *roots, int n) { // Добавлен const
    for (int i = 0; i < n; i++) {
        printf("%.6lf", roots[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}
