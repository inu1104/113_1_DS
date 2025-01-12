int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int *result = malloc((digitsSize + 1) * sizeof(int));
    (*returnSize) = digitsSize + 1;

    int sum, carry = 1;
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        sum = digits[i] + carry;
        carry = sum / 10;
        result[i + 1] = sum % 10;
    }
    result[0] = carry;

    if (carry == 0)
    {
        for (int i = 0; i < digitsSize; i++)
            result[i] = result[i + 1];
        (*returnSize)--;
        result = realloc(result, digitsSize * sizeof(int));
    }

    return result;
}
