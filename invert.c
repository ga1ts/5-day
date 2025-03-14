#include <stdio.h>
#include <stdlib.h>

// Прототипы функций
void input_size(int *rows, int *cols, int *error_flag);
void allocate_pointer(double ***ptr, double **data, int rows, int cols);
void input_matrix(double **matrix_elements, int rows, int cols, int *error_flag);
void output_matrix(double **matrix_elements, int rows, int cols);
void free_matrix(double **matrix, int rows);
double calculate_determinant(double **matrix, int n);
double **get_minor(double **matrix, int n, int row, int col);
double **calculate_algebraic_complements(double **matrix, int n);
double **transpose_matrix(double **matrix, int n);
double **invert_matrix(double **matrix, int n, int *error_flag);

// Главная функция
int main() {
    int rows, cols, error_flag = 0;

    // Ввод размеров матрицы
    input_size(&rows, &cols, &error_flag);

    // Проверка на ошибки
    if (error_flag || rows != cols) {
        printf("n/a");
        return 0;
    }

    // Выделение памяти
    double *data = (double *)malloc(rows * cols * sizeof(double));
    double **matrix = (double **)malloc(rows * sizeof(double *));
    allocate_pointer(&matrix, &data, rows, cols);

    // Ввод элементов матрицы
    input_matrix(matrix, rows, cols, &error_flag);

    if (error_flag) {
        printf("n/a");
        free(data);
        free(matrix);
        return 0;
    }

    // Вычисление обратной матрицы
    double **inverse = invert_matrix(matrix, rows, &error_flag);

    if (error_flag) {
        printf("n/a");
    } else {
        // Вывод обратной матрицы
        output_matrix(inverse, rows, cols);
    }

    // Освобождение памяти
    free(data);
    free(matrix);
    if (!error_flag) {
        free(inverse[0]);
        free(inverse);
    }

    return 0;
}

// Функция ввода размеров матрицы
void input_size(int *rows, int *cols, int *error_flag) {
    char c1, c2;
    if (scanf("%d%c%d%c", rows, &c1, cols, &c2) != 4 || c1 != ' ' || c2 != '\n' || *rows <= 0 || *cols <= 0) {
        *error_flag = 1;
    }
}

// Функция выделения памяти для указателей на строки
void allocate_pointer(double ***ptr, double **data, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        (*ptr)[i] = *data + i * cols;
    }
}

// Функция ввода элементов матрицы
void input_matrix(double **matrix_elements, int rows, int cols, int *error_flag) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%lf", &matrix_elements[i][j]) != 1) {
                *error_flag = 1;
                return;
            }
        }
    }
}

// Функция вывода матрицы
void output_matrix(double **matrix_elements, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.6f", matrix_elements[i][j]);
            if (j < cols - 1) {
                printf(" ");
            }
        }
        if (i < rows - 1) {
            printf("\n");
        }
    }
}

// Функция освобождения памяти матрицы
void free_matrix(double **matrix, int rows) {
    free(matrix[0]);
    free(matrix);
}

// Функция вычисления определителя
double calculate_determinant(double **matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double determinant = 0.0;
    for (int j = 0; j < n; j++) {
        double **minor_matrix = get_minor(matrix, n, 0, j);
        determinant += ((j % 2 ? -1 : 1) * matrix[0][j] * calculate_determinant(minor_matrix, n - 1));
        free_matrix(minor_matrix, n - 1);
    }
    return determinant;
}

// Функция получения минора
double **get_minor(double **matrix, int n, int row, int col) {
    double *data = (double *)malloc((n - 1) * (n - 1) * sizeof(double));
    double **minor = (double **)malloc((n - 1) * sizeof(double *));
    allocate_pointer(&minor, &data, n - 1, n - 1);
    for (int i = 0, mi = 0; i < n; i++) {
        if (i == row) continue;
        for (int j = 0, mj = 0; j < n; j++) {
            if (j == col) continue;
            minor[mi][mj] = matrix[i][j];
            mj++;
        }
        mi++;
    }
    return minor;
}

// Функция вычисления алгебраических дополнений
double **calculate_algebraic_complements(double **matrix, int n) {
    double *data = (double *)malloc(n * n * sizeof(double));
    double **result = (double **)malloc(n * sizeof(double *));
    allocate_pointer(&result, &data, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double **minor_matrix = get_minor(matrix, n, i, j);
            result[i][j] = ((i + j) % 2 ? -1 : 1) * calculate_determinant(minor_matrix, n - 1);
            free_matrix(minor_matrix, n - 1);
        }
    }
    return result;
}

// Функция транспонирования матрицы
double **transpose_matrix(double **matrix, int n) {
    double *data = (double *)malloc(n * n * sizeof(double));
    double **transposed = (double **)malloc(n * sizeof(double *));
    allocate_pointer(&transposed, &data, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

// Функция вычисления обратной матрицы
double **invert_matrix(double **matrix, int n, int *error_flag) {
    double determinant = calculate_determinant(matrix, n);
    if (determinant == 0.0) {
        *error_flag = 1;
        return NULL;
    }
    double **complements = calculate_algebraic_complements(matrix, n);
    double **transposed = transpose_matrix(complements, n);
    double *data = (double *)malloc(n * n * sizeof(double));
    double **inverse = (double **)malloc(n * sizeof(double *));
    allocate_pointer(&inverse, &data, n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = transposed[i][j] / determinant;
        }
    }
    free_matrix(complements, n);
    free_matrix(transposed, n);
    return inverse;
}
