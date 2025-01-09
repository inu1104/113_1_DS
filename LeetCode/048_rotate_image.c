void rotate(int **matrix, int matrixSize, int *matrixColSize)
{
    int x = (matrixSize % 2 == 0) ? (matrixSize / 2) : (matrixSize / 2 + 1);
    int y = matrixSize / 2;
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", matrix[i][j]);
            int temp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - j - 1][i];
            matrix[matrixSize - j - 1][i] = matrix[matrixSize - i - 1][matrixSize - j - 1];
            matrix[matrixSize - i - 1][matrixSize - j - 1] = matrix[j][matrixSize - i - 1];
            matrix[j][matrixSize - i - 1] = temp;
        }
    }
}
