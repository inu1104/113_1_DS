int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int numIdenticalPairs(int *nums, int numsSize)
{
    int result = 0;
    qsort(nums, numsSize, sizeof(int), compare);

    int temp = 1;
    int current_num = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == current_num)
            temp++;
        else
        {
            result += temp * (temp - 1) / 2;
            current_num = nums[i];
            temp = 1;
        }
    }
    result += temp * (temp - 1) / 2;
    return result;
}
