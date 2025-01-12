char *defangIPaddr(char *address)
{
    int i = 0, j = 0;
    int len = strlen(address);

    char *result = malloc((len + 7) * sizeof(char));
    while (address[i] != '\0')
    {
        printf("%c", address[i]);
        if (address[i] == '.')
        {
            result[j] = '[';
            result[j + 1] = '.';
            result[j + 2] = ']';
            j += 3;
        }
        else
        {
            result[j] = address[i];
            j++;
        }
        i++;
    }
    result[j] = '\000';
    return result;
}
