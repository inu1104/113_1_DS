double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    int *mergedArr = (int *)malloc((nums1Size + nums2Size) * sizeof(int));
    int idx1 = 0, idx2 = 0, idx_merged = 0;
    while (idx1 < nums1Size && idx2 < nums2Size)
    {
        if (nums1[idx1] < nums2[idx2])
        {
            mergedArr[idx_merged] = nums1[idx1];
            idx1++;
        }
        else
        {
            mergedArr[idx_merged] = nums2[idx2];
            idx2++;
        }
        idx_merged++;
    }
    while (idx1 < nums1Size)
    {
        mergedArr[idx_merged] = nums1[idx1];
        idx1++;
        idx_merged++;
    }
    while (idx2 < nums2Size)
    {
        mergedArr[idx_merged] = nums2[idx2];
        idx2++;
        idx_merged++;
    }

    int mergedSize = nums1Size + nums2Size;
    return (mergedSize % 2) ? mergedArr[mergedSize / 2] : (mergedArr[mergedSize / 2 - 1] + mergedArr[mergedSize / 2]) / 2.0;
}
