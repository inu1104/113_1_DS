inline int time_to_min(char *time)
{
    int result = 0;
    result += (time[0] - 0) * 10 * 60;
    result += (time[1] - 0) * 60;
    result += (time[3] - 0) * 10;
    result += (time[4] - 0);
    return result;
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findMinDifference(char **timePoints, int timePointsSize)
{
    int mindiff, maxdiff;
    int *timePointsMin = (int *)malloc(timePointsSize * sizeof(int));

    for (int i = 0; i < timePointsSize; i++)
        timePointsMin[i] = time_to_min(timePoints[i]);
    qsort(timePointsMin, timePointsSize, sizeof(int), compare);

    maxdiff = timePointsMin[timePointsSize - 1] - timePointsMin[0];
    mindiff = maxdiff;
    for (int i = 0; i < timePointsSize - 1; i++)
        mindiff = mindiff > (timePointsMin[i + 1] - timePointsMin[i]) ? (timePointsMin[i + 1] - timePointsMin[i]) : mindiff;
    mindiff = mindiff > (60 * 24 - maxdiff) ? (60 * 24 - maxdiff) : mindiff;

    return mindiff;
}
