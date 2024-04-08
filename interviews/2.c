#define TRUE (1)
#define FALSE (0)

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    char* row_is_zero = (char*)malloc(sizeof(char) * matrixSize);
    memset(row_is_zero, FALSE, sizeof(char) * matrixSize);
    char* col_is_zero = (char*)malloc(sizeof(char) * matrixColSize[0]);
    memset(col_is_zero, FALSE, sizeof(char) * matrixColSize[0]);
    for (int i = 0 ; i < matrixSize ; i++) {
        for (int j = 0 ; j < matrixColSize[i] ; j++) {
            if (matrix[i][j] == 0) {
                row_is_zero[i] = TRUE;
                col_is_zero[j] = TRUE;
            }
        }
    }


    for (int i = 0 ; i < matrixSize ; i++) {
        for (int j = 0 ; j < matrixColSize[i] ; j++) {
            if (row_is_zero[i] || col_is_zero[j]) {
                matrix[i][j] = 0;
            }
        }
    }

}