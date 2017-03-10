#include <stdio.h>
#include <stdlib.h>

struct S{
    int value;
    struct S *next;
};

typedef struct S node;

node *top;

void push(int x)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->next=top;
    temp->value=x;
    top =temp;
}


void create()
{
    int x;
    scanf("%d",&x);

    if(x!=0)
    {
        if(x>(top->value))
        {
            push(x);
            printf("%d ",x);
        }
        create();
    }


}

int pop()
{
    int x=top->value;
    node *temp;
    temp=top;
    top=top->next;
    free(temp);
    return x;
}

void print()
{
    if(top->next!=NULL)
    {
        printf("%d ",pop());
        print();
    }
}


int main()
{
    top=(node *)malloc(sizeof(node));
    top->next=NULL;
    top->value=0;
    create();
    puts("\nPopped:");
    print();
}
