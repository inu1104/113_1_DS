int numberOfBeams(char **bank, int bankSize)
{
    int last = 0, current, result = 0;
    for (int i = 0; i < bankSize; i++)
    {
        current = 0;
        for (int j = 0; bank[i][j] != '\000'; j++)
            current += (bank[i][j] - '0');
        if(current > 0){
            result += last * current;
            last = current;
        }

    }
    return result;
}
