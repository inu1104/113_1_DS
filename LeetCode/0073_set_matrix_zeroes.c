void setZeroes(int **matrix, int matrixSize, int *matrixColSize)
{
    int *row_is_0 = calloc(matrixSize, sizeof(int));
    int *col_is_0 = calloc(*matrixColSize, sizeof(int));
    for (int i = 0; i < matrixSize; i++)
    {
        for (int j = 0; j < *matrixColSize; j++)
        {
            if (!matrix[i][j])
            {
                row_is_0[i] = 1;
                col_is_0[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < *matrixColSize; j++)
            if (row_is_0[i] || col_is_0[j])
                matrix[i][j] = 0;
}
