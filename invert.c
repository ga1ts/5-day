#include <stdio.h>
#include <stdlib.h>

void input_size(int *n_size_row, int *n_size_col, int *flag);
void pointer_allocated(double **pointer_el, double *matrix_num, int n_size_row, int n_size_col);
void input_num(double **pointer_el, int n_size_row, int n_size_col, int *flag);
void output_matrix(double **matrix_num, int n_size_row, int n_size_col);
double determine(double **matrix, int n_size_row);
double **minor(double **matrix, int n_size_row, int row, int col);
double **algebraic_complements(double **matrix, int n_size_row);
double **transpose(double **matrix, int n_size_row);
double **invert_matrix(double **matrix, int n_size_row, int *flag);

int main() {
    int n_size_row, n_size_col, flag = 0;
    input_size(&n_size_row, &n_size_col, &flag);
    if (flag == 0) {
        if (n_size_row != n_size_col) {
            // Матрица не квадратная
            printf("n/a");
            return 0;
        }

        double *matrix = (double *)malloc(n_size_row * n_size_col * sizeof(double));
        double **pointer_el = (double **)malloc(n_size_row * sizeof(double *));
        pointer_allocated(pointer_el, matrix, n_size_row, n_size_col);

        input_num(pointer_el, n_size_row, n_size_col, &flag);

        if (flag == 0) {
            double **inverse = invert_matrix(pointer_el, n_size_row, &flag);
            if (flag == 0) {
                output_matrix(inverse, n_size_row, n_size_col);
            } else {
                printf("n/a");
            }

            free(inverse[0]);
            free(inverse);
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
    char c, c1;
    if (scanf("%d%c%d%c", n_size_row, &c, n_size_col, &c1) != 4 || c != ' ' || c1 != '\n' || *n_size_row <= 0 || *n_size_col <= 0) {
        *flag = 1;
    }
}

void pointer_allocated(double **pointer_el, double *matrix_num, int n_size_row, int n_size_col) {
    for (int i = 0; i < n_size_row; i++) {
        pointer_el[i] = matrix_num + i * n_size_col;
    }
}

void input_num(double **pointer_el, int n_size_row, int n_size_col, int *flag) {
    *flag = 0;
    double temp;
    char c;
    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_col; j++) {
            if (scanf("%lf%c", &temp, &c) == 2 && (c == ' ' || c == '\n')) {
                pointer_el[i][j] = temp;
            } else {
                *flag = 1;
                return;
            }
        }
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

double determine(double **matrix, int n_size_row) {
    if (n_size_row == 1) {
        return matrix[0][0];
    }

    if (n_size_row == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;
    for (int i = 0; i < n_size_row; i++) {
        double **minor_matrix = minor(matrix, n_size_row, 0, i);
        double cofactor = (i % 2 == 0 ? 1 : -1) * matrix[0][i] * determine(minor_matrix, n_size_row - 1);
        det += cofactor;

        free(minor_matrix[0]);
        free(minor_matrix);
    }
    return det;
}

double **minor(double **matrix, int n_size_row, int row, int col) {
    double *minor_data = (double *)malloc((n_size_row - 1) * (n_size_row - 1) * sizeof(double));
    double **minor_matrix = (double **)malloc((n_size_row - 1) * sizeof(double *));
    pointer_allocated(minor_matrix, minor_data, n_size_row - 1, n_size_row - 1);

    for (int i = 0, mi = 0; i < n_size_row; i++) {
        if (i == row) continue;
        for (int j = 0, mj = 0; j < n_size_row; j++) {
            if (j == col) continue;
            minor_matrix[mi][mj] = matrix[i][j];
            mj++;
        }
        mi++;
    }
    return minor_matrix;
}

double **algebraic_complements(double **matrix, int n_size_row) {
    double *data = (double *)malloc(n_size_row * n_size_row * sizeof(double));
    double **result = (double **)malloc(n_size_row * sizeof(double *));
    pointer_allocated(result, data, n_size_row, n_size_row);

    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_row; j++) {
            double **minor_matrix = minor(matrix, n_size_row, i, j);
            result[i][j] = determine(minor_matrix, n_size_row - 1) * ((i + j) % 2 == 0 ? 1 : -1);

            free(minor_matrix[0]);
            free(minor_matrix);
        }
    }
    return result;
}

double **transpose(double **matrix, int n_size_row) {
    double *data = (double *)malloc(n_size_row * n_size_row * sizeof(double));
    double **transposed = (double **)malloc(n_size_row * sizeof(double *));
    pointer_allocated(transposed, data, n_size_row, n_size_row);

    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_row; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    return transposed;
}

double **invert_matrix(double **matrix, int n_size_row, int *flag) {
    double det = determine(matrix, n_size_row);
    if (det == 0) {
        *flag = 1;  // Обратной матрицы не существует
        return NULL;
    }

    double **complements = algebraic_complements(matrix, n_size_row);
    double **transposed = transpose(complements, n_size_row);

    double *data = (double *)malloc(n_size_row * n_size_row * sizeof(double));
    double **inverse = (double **)malloc(n_size_row * sizeof(double *));
    pointer_allocated(inverse, data, n_size_row, n_size_row);

    for (int i = 0; i < n_size_row; i++) {
        for (int j = 0; j < n_size_row; j++) {
            inverse[i][j] = transposed[i][j] / det;
        }
    }

    free(complements[0]);
    free(complements);
    free(transposed[0]);
    free(transposed);

    return inverse;
}
