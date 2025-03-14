#include <stdio.h>
#include <stdlib.h>

void input_size(int *n_size_row, int *n_size_col, int *flag);
void pointer_allocation(double **pointer_el, double *matrix_num, int n_size_row, int n_size_col);
void input_num(double **pointer_el, int n_size_row, int n_size_col, int *flag);
void output_matrix(double **matrix_num, int n_size_row, int n_size_col);
double determinant(double **matrix, int n_size);
double **minor_matrix(double **matrix, int n_size, int exclude_row, int exclude_col);
void free_matrix(double **matrix, int n_size);

int main() {
    int n_size_row, n_size_col, flag;
    input_size(&n_size_row, &n_size_col, &flag);

    if (flag == 0) {
        if (n_size_row != n_size_col) {  // Определитель только для квадратной матрицы
            printf("n/a");
            return 0;
        }

        double *matrix = (double *)malloc(n_size_col * n_size_row * sizeof(double));
        double **pointer_el = (double **)malloc(n_size_row * sizeof(double *));
        pointer_allocation(pointer_el, matrix, n_size_row, n_size_col);

        input_num(pointer_el, n_size_row, n_size_col, &flag);

        if (flag == 0) {
            double det = determinant(pointer_el, n_size_row);
            printf("%.6f", det);
        } else {
            printf("n/a");
        }

        free(matrix);
        free(pointer_el);
    } else {
        printf("n/a");
    }

    return 0;
}

void input_size(int *n_size_row, int *n_size_col, int *flag) {
    *flag = 0;
    char c;
    if (scanf("%d %d%c", n_size_row, n_size_col, &c) == 3 && c == '\n' && *n_size_row > 0 && *n_size_col > 0) {
        return;
    } else {
        *flag = 1;
    }
}

void input_num(double **pointer_el, int n_size_row, int n_size_col, int *flag) {
    *flag = 0;
    double p_val;
    char space_or_newline;

    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_col; j++) {
            if (scanf("%lf%c", &p_val, &space_or_newline) == 2 && (space_or_newline == ' ' || space_or_newline == '\n')) {
                pointer_el[i][j] = p_val;
            } else {
                *flag = 1;
                return;
            }
        }
    }
}

void pointer_allocation(double **pointer_el, double *matrix_num, int n_size_row, int n_size_col) {
    for (int i = 0; i < n_size_row; i++) {
        pointer_el[i] = matrix_num + i * n_size_col;
    }
}

void output_matrix(double **matrix_num, int n_size_row, int n_size_col) {
    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_col; j++) {
            if (j == n_size_col - 1) {
                printf("%.6f", matrix_num[i][j]);
            } else {
                printf("%.6f ", matrix_num[i][j]);
            }
        }
        if (i != n_size_row - 1) {
            printf("\n");
        }
    }
}

double determinant(double **matrix, int n_size) {
    if (n_size == 1) {
        return matrix[0][0];
    } else if (n_size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double det = 0.0;

        for (int col = 0; col < n_size; col++) {
            double **submatrix = minor_matrix(matrix, n_size, 0, col);
            double minor_det = determinant(submatrix, n_size - 1);
            det += ((col % 2 == 0 ? 1 : -1) * matrix[0][col] * minor_det);

            free_matrix(submatrix, n_size - 1);
        }

        return det;
    }
}

double **minor_matrix(double **matrix, int n_size, int exclude_row, int exclude_col) {
    double *minor_data = (double *)malloc((n_size - 1) * (n_size - 1) * sizeof(double));
    double **minor = (double **)malloc((n_size - 1) * sizeof(double *));
    for (int i = 0; i < n_size - 1; i++) {
        minor[i] = minor_data + i * (n_size - 1);
    }

    int minor_row = 0, minor_col = 0;
    for (int i = 0; i < n_size; i++) {
        if (i == exclude_row) continue;

        minor_col = 0;
        for (int j = 0; j < n_size; j++) {
            if (j == exclude_col) continue;

            minor[minor_row][minor_col] = matrix[i][j];
            minor_col++;
        }
        minor_row++;
    }

    return minor;
}

void free_matrix(double **matrix, int n_size) {
    free(matrix[0]);  // Освобождаем первую строку (данные)
    free(matrix);     // Освобождаем сам массив указателей
}
