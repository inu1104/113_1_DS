int minimumOperations(int *nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; i++)
        result += (nums[i] % 3) ? 1 : 0;
    return result;
}
