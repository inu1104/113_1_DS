#define empty(s) !s.size

typedef struct stack
{
    char arr[10004];
    int size;
} Stack;

void push(Stack *s, char c)
{
    s->arr[s->size] = c;
    s->size++;
}

char pop(Stack *s)
{
    s->size--;
    return s->arr[s->size];
}

bool parseBoolExpr(char *expression)
{
    char c;
    int idx = 0;
    Stack s;
    while (expression[idx] != '\000')
    {
        if (expression[idx] == ')')
        {
            int num_of_bool[2] = {0, 0};
            do
            {
                c = pop(&s);
                if (c == 't')
                    num_of_bool[1]++;
                else if (c == 'f')
                    num_of_bool[0]++;
            } while (c != '(');

            c = pop(&s);
            switch (c)
            {
            case '!':
                if (num_of_bool[0])
                    push(&s, 't');
                else
                    push(&s, 'f');
                break;
            case '&':
                if (num_of_bool[0])
                    push(&s, 'f');
                else
                    push(&s, 't');
                break;
            case '|':
                if (num_of_bool[1])
                    push(&s, 't');
                else
                    push(&s, 'f');
                break;
            }
        }
        else
        {
            if (expression[idx] != ',')
                push(&s, expression[idx]);
        }
        idx++;
    }

    c = pop(&s);
    return c == 't';
}
