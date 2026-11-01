#include <stdio.h>

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

int matches(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int main(void)
{
    char expression[N];
    int i = 0;
    int valid = 1;
    char symbol;

    printf("Enter parentheses: ");
    scanf("%99s", expression);

    while (expression[i] != '\0')
    {
        symbol = expression[i];

        if (symbol == '(' || symbol == '[' || symbol == '{')
        {
            push(symbol);
        }
        else if (symbol == ')' || symbol == ']' || symbol == '}')
        {
            if (top == -1 || !matches(pop(), symbol))
            {
                valid = 0;
                break;
            }
        }
        else
        {
            valid = 0;
            break;
        }

        i = i + 1;
    }

    if (top != -1)
    {
        valid = 0;
    }

    if (valid)
    {
        printf("Valid Parentheses\n");
    }
    else
    {
        printf("Invalid Parentheses\n");
    }

    return 0;
}
