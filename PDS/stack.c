#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct{
    int st[SIZE];
    int top;
}STACK;

void create(STACK *s)
{
    s->top=-1;
}

void push(STACK *s,int a)
{
    (s->top)++;
    s->st[s->top]=a;
}

int pop(STACK *s)
{
    int x=s->st[s->top];
    (s->top)--;
    return x;
}

void print(STACK *s)
{
    int i;
    while((s->top)>=0)
    {
        printf("%d ",s->st[s->top]);
        s->top--;
    }
}


int main()
{
    int x=0;
    STACK *s;
    s=(STACK *)malloc(sizeof(STACK));
    create(s);
    while(1)
    {
        printf("Enter the value of insert in stack (0 to exit):-");
        scanf("%d",&x);
        if(x==0)
            break;
        else
            push(s,x);
    }
    puts("Stack is:-");
    print(s);
}
