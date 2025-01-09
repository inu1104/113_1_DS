int lengthOfLongestSubstring(char *s)
{
    if (strlen(s) == 0)
        return 0;
    int head = 0, rear = 0, len = 1, maxlen = 1;

    int recordSize = 128;
    int *record = (int *)malloc(recordSize * sizeof(int));
    for (int idx = 0; idx < recordSize; idx++)
        record[idx] = 0;
    // record numbers of element in s[head] to s[rear]

    while (rear < strlen(s))
    {
        len = rear - head + 1;

        if (head == rear)
        {
            record[s[rear]] = 1;
            rear++;
        }
        else
        {
            if (record[s[rear]] == 0)
            {
                record[s[rear]]++;
                rear++;
                maxlen = len > maxlen ? len : maxlen;
            }
            else
            {
                record[s[head]]--;
                head++;
            }
        }
    }

    return maxlen;
}
