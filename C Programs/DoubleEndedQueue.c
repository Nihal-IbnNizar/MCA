#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node queue;
enum op {ENQUEUE_FRONT = 1, ENQUEUE_REAR, DEQUEUE_FRONT, DEQUEUE_REAR, EXIT};

queue *front = NULL, *rear = NULL;

void enqueueFront(int e)
{
    queue *t = (queue *)malloc(sizeof(queue));
    t->data = e;
    t->next = NULL;
    if (front == NULL)
    {
        front = t;
        rear = t;
    }
    else
    {
        t->next = front;
        front = t;
    }
}

void enqueueRear(int e)
{
    queue *t = (queue *)malloc(sizeof(queue));
    t->data = e;
    t->next = NULL;
    if (rear == NULL)
    {
        front = t;
        rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

void dequeueFront()
{
    if (front == NULL)
        printf("\nEmpty QUEUE");
    else
    {
        printf("\nDequeuing element %d", front->data);
        queue *temp = front;
        front = front->next;
        free(temp);
        if (front == NULL)
            rear = NULL;
    }
}

void dequeueRear()
{
    if (front == NULL)
        printf("\nEmpty QUEUE");
    else
    {
        if (front == rear)
        {
            printf("\nDequeuing element %d", front->data);
            free(front);
            front = rear = NULL;
        }
        else
        {
            queue *temp = front;
            while (temp->next != rear)
            {
                temp = temp->next;
            }
            printf("\n%d", rear->data);
            free(rear);
            rear = temp;
            rear->next = NULL;
        }
    }
}

int menu()
{
    int ch;
    printf("\nENQUEUE Front - 1\nENQUEUE Rear - 2\nDEQUEUE Front - 3\nDEQUEUE Rear - 4\nEXIT - 5\nYour Choice : ");
    scanf("%d", &ch);
    return ch;
}

void process()
{
    int ch;
    for (ch = menu(); ch != 5; ch = menu())
    {
        switch(ch)
        {
            case ENQUEUE_FRONT:
                printf("Enter the element to enqueue at the front: ");
                scanf("%d", &ch);
                enqueueFront(ch);
                break;
            case ENQUEUE_REAR:
                printf("Enter the element to enqueue at the rear: ");
                scanf("%d", &ch);
                enqueueRear(ch);
                break;
            case DEQUEUE_FRONT:
                dequeueFront();
                break;
            case DEQUEUE_REAR:
                dequeueRear();
                break;
        }
    }
}

int main()
{
    process();
    return 0;
}