#include <stdio.h>
#include <ctype.h>

#define N 100

char stack[N];
int top = -1;

void push(char value)
{
    top = top + 1;
    stack[top] = value;
}

char pop(void)
{
    char value = stack[top];
    top = top - 1;
    return value;
}

char peek(void)
{
    return stack[top];
}

int precedence(char operator)
{
    if (operator == '+' || operator == '-')
    {
        return 1;
    }

    if (operator == '*' || operator == '/')
    {
        return 2;
    }

    return 0;
}

int main(void)
{
    char infix[N];
    char postfix[N];
    int i = 0;
    int j = 0;
    char symbol;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    while (infix[i] != '\0')
    {
        symbol = infix[i];

        if (isalnum((unsigned char)symbol))
        {
            postfix[j] = symbol;
            j = j + 1;
        }
        else if (symbol == '(')
        {
            push(symbol);
        }
        else if (symbol == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j] = pop();
                j = j + 1;
            }

            if (top != -1 && peek() == '(')
            {
                pop();
            }
        }
        else
        {
            while (top != -1 && peek() != '(' &&
                   precedence(peek()) >= precedence(symbol))
            {
                postfix[j] = pop();
                j = j + 1;
            }

            push(symbol);
        }

        i = i + 1;
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j = j + 1;
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
