#include <stdio.h>

#define N 5

int stack[N];
int top = -1;

void push(int x)
{
    if (top >= N - 1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }

    top = top + 1;
    stack[top] = x;
}

int pop(void)
{
    if (top == -1)
    {
        printf("STACK UNDERFLOW ON POP\n");
        return -1;
    }

    top = top - 1;
    return stack[top + 1];
}

int main(void)
{
    push(10);
    push(20);
    push(30);

    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}
