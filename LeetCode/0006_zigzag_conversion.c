char *convert(char *s, int numRows)
{
    if(numRows == 1) return s;
    int row = 0, plus;
    int len = strlen(s);

    int *c_each_row = malloc(numRows * sizeof(int));
    char *result = malloc((len + 1) * sizeof(char));

    // calculate number of chars of each row
    for (int i = 0; i < numRows; i++)
    {
        c_each_row[i] = len / ((numRows - 1) * 2);
        if (i != 0 && i != (numRows - 1))
            c_each_row[i] *= 2;
    }
    for (int i = 0; i < len % ((numRows - 1) * 2); i++)
    {
        c_each_row[row]++;
        if (row == 0)
            plus = 1;
        if (row == numRows - 1)
            plus = -1;
        row += plus;
    }

    // calculate last idx of char in i-th row
    c_each_row[0]--;
    for (int i = 1; i < numRows; i++)
        c_each_row[i] += c_each_row[i - 1];

    for (int i = 0; i < numRows; i++)
        printf("%d ", c_each_row[i]);

    printf("%d %d", plus, row);

    int idx = len - 1;
    plus = (plus == 1) ? -1 : 1;
    row += plus;
    while (idx >= 0)
    {
        result[c_each_row[row]] = s[idx];
        c_each_row[row]--;
        if (row == 0)
            plus = 1;
        if (row == numRows - 1)
            plus = -1;
        row += plus;
        idx--;
    }
    result[len] = '\000';

    return result;
}
