bool isValid(char *s)
{
    int top = -1, len = strlen(s);
    char *stack = malloc(len * sizeof(char));

    int idx = 0;
    while (s[idx] != '\000')
    {
        char temp;
        if (s[idx] == '{' || s[idx] == '[' || s[idx] == '(')
        {
            top++;
            stack[top] = s[idx];
        }
        else
        {
            if(top == -1)
                return false;
            temp = stack[top];
            switch (s[idx])
            {
            case '}':
                if (temp != '{')
                    return false;
                break;
            case ']':
                if (temp != '[')
                    return false;
                break;
            case ')':
                if (temp != '(')
                    return false;
                break;
            }
            top--;
        };

        idx++;
    }

    return top == -1;
}
