#include <stdio.h>
#include <stdlib.h>

struct name
{
    int number;
    struct name *next;
};

typedef struct name node;

void create(node *list)
{
    printf("Input a number\nType-497 to exit:-");
    scanf("%d",&list->number);

    if(list->number==-497)
    {
        list->next=NULL;
    }
    else
    {
        list->next=(node *)malloc(sizeof(node));
        create(list->next);
    }
}

void modify(node *list)
{
    if((list->next)->next==NULL)
    {
        free(list->next);
        list->next=NULL;
    }
    else
        modify(list->next);
}

void print(node *list)
{
    if(list->next!=NULL)
    {
        printf("%d-->",list->number);

        if(list->next->next==NULL)
            printf("%d",list->next->number);
        print(list->next);
    }
}


int main()
{
    node *head;
    head=(node *)malloc(sizeof(node));
    create(head);
    modify(head);
    print(head);
}
