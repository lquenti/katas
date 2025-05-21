#include<stdlib.h>
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    int *ms = calloc(m, sizeof(int));
    int *ns = calloc(n, sizeof(int));
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (matrix[i][j] == 0) {
                ms[i] = 1;
                ns[j] = 1;
            }
        }
    }
    for (int i=0; i<m; ++i) {
        if (ms[i]) {
            for (int j=0; j<n; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i=0; i<n; ++i) {
        if (ns[i]) {
            for (int j=0; j<m; ++j) {
                matrix[j][i] = 0;
            }
        }
    }
    free(ms);
    free(ns);
}
