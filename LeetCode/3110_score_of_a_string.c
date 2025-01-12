int scoreOfString(char *s)
{
    int sum = 0;
    for (int i = 1; s[i] != '\000'; i++)
    {
        int score = s[i] - s[i - 1];
        sum += score > 0 ? score : -score;
    }
    return sum;
}
