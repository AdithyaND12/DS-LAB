#include <stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void insert(void)
{
    int value;

    if (rear == N - 1)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1)
    {
        front = 0;
    }

    rear = rear + 1;
    queue[rear] = value;
    printf("Value inserted\n");
}

void delete_value(void)
{
    if (front == -1 || front > rear)
    {
        printf("QUEUE EMPTY\n");
        return;
    }

    printf("Deleted value: %d\n", queue[front]);
    front = front + 1;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void display(void)
{
    int i;

    if (front == -1)
    {
        printf("QUEUE EMPTY\n");
        return;
    }

    printf("Queue: ");

    for (i = front; i <= rear; i = i + 1)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main(void)
{
    int choice;

    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            insert();
        }
        else if (choice == 2)
        {
            delete_value();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            printf("Program ended\n");
        }
        else
        {
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
