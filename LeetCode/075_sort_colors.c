void merge(int *arr, int head, int rear)
{
    if (head == rear)
        return;
    int middle = (head + rear) / 2;
    merge(arr, head, middle);
    merge(arr, middle + 1, rear);

    int idx_l = head, idx_r = middle + 1, idx_merged = 0;
    int *temp = (int *)malloc((rear - head + 1) * sizeof(int));
    while (idx_l <= middle && idx_r <= rear)
    {
        if (arr[idx_r] < arr[idx_l])
        {
            temp[idx_merged] = arr[idx_r];
            idx_r++;
        }
        else
        {
            temp[idx_merged] = arr[idx_l];
            idx_l++;
        }
        idx_merged++;
    }
    while (idx_l <= middle)
    {
        temp[idx_merged] = arr[idx_l];
        idx_l++;
        idx_merged++;
    }
    while (idx_r <= rear)
    {
        temp[idx_merged] = arr[idx_r];
        idx_r++;
        idx_merged++;
    }

    for (int i = head; i <= rear; i++)
        arr[i] = temp[i - head];
}

void sortColors(int *nums, int numsSize)
{
    int head = 0, rear = numsSize - 1;
    merge(nums, head, rear);
}
