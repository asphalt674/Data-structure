#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Stack;
void push(Stack **top)
{
    printf("Enter value\n");
    Stack *var=(Stack *)malloc(sizeof(Stack));
    scanf("%d",&var->data);
    var->next=NULL;
    if(*top==NULL)
    {
        *top=var;
    }
    else
    {
        var->next=*top;
        *top=var;
    }
}
void pop(Stack **top)
{
    if(*top==NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        Stack *t;
        t=*top;
        t->next=NULL;
        printf("%d got deleted\n",(*top)->data);
        *top=(*top)->next;
        free(t);
        //for(t=*top;t->next!=NULL;t=t->next);
    }
    
}
void display(Stack **top)
{
    if(*top==NULL)
    {
        printf("Stack underflow\n");
    }
    else
    {
        Stack *t;
        printf("The elements of the Stack are\n");
        for(t=*top;t!=NULL;t=t->next)
        {
            printf("%d ",t->data);
        }
        printf("\n");
    }
}
int main()
{
    Stack *top=NULL;
    int c,loop=1;
    while(loop)
    {
        printf("Enter choice\n");
        printf("1 for Input\n");
        printf("2 for Pop\n");
        printf("3 for Display\n");
        printf("0 for exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                push(&top);
                break;
            }
            case 2:
            {
               pop(&top);
                break;
            }
            case 3:
            {
                display(&top);
                break;
            }
            case 4:
            {
                loop=0;
                break;
            }
            default:
            {
                printf("Give valid Input\n");
            }
        }
    }
}
