int *minOperations(char *boxes, int *returnSize)
{
    int size = strlen(boxes);
    *returnSize = size;
    int *result = malloc(size * sizeof(int));

    int sum = 0, left = 0, right = 0;
    for (int i = 0; i < size; i++)
    {
        sum += (boxes[i] - '0') * i;
        right += (boxes[i] - '0');
    }

    for (int i = 0; i < size; i++)
    {
        right -= (boxes[i] - '0');
        result[i] = sum;
        sum -= right;
        left += (boxes[i] - '0');
        sum += left;
    }

    return result;
}
