#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
    int q[100];
    int front,rear;
}queue;

void create(queue *runs)
{
    runs->front=0;
    runs->rear=0;
}

void enqueue(queue *runs,int x)
{
    if(runs->front==runs->rear)
    {
        runs->q[runs->front]=x;
        (runs->rear)++;
    }
    else
    {
        runs->q[runs->rear]=x;
        (runs->rear)++;
    }
}

void ask(queue *runs)
{
    int x;
    while(1)
    {
        printf("Enter the value for queue(0 to exit):-");
        scanf("%d",&x);
        if(x==0)
            break;
        else
        {
            enqueue(runs,x);
        }
    }
}

int dequeue(queue *runs)
{
    int x=runs->q[runs->front];
    (runs->front)++;
    return x;

}

void display(queue *runs)
{
    int i=0;
    for(i=runs->front;i<runs->rear;i++)
        printf("%d ", runs->q[i]);
}


int main()
{
    int x,i,f;
    char a;

    queue runs;
    create(&runs);

    while(1)
    {
        printf("\nEnter an operation (e for enqueue, d for dequeue, p for display, b for exit:-\n ");
        scanf("%c",&a);

        if(a=='b')
            break;
        if(a=='e')
            ask(&runs);
        if(a=='d')
        {
            printf("Enter the number of values to be dequeued\n");
            scanf("%d",&x);

            for(i=0;i<x;i++)
                f=dequeue(&runs);
        }
        if(a=='p')
        {
            display(&runs);
        }
    }


}
