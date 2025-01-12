int compare(const void *a, const void *b) { return *(char *)a - *(char *)b; }

int numJewelsInStones(char *jewels, char *stones)
{
    int result = 0;
    int jewel_len = strlen(jewels);
    int stone_len = strlen(stones);

    qsort(jewels, jewel_len, sizeof(char), compare);
    qsort(stones, stone_len, sizeof(char), compare);

    int i = 0, j = 0;
    while (jewels[j] && stones[i])
    {
        if (stones[i] == jewels[j])
        {
            result++;
            i++;
        }
        else
        {
            if (stones[i] > jewels[j])

                j++;
            else
                i++;
        }
    }
    return result;
}
