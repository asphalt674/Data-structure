#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Queque;
void enQueque(Queque **f,Queque **r)
{
    printf("enter value\n");
    Queque *var=(Queque *)malloc(sizeof(Queque));
    var->next=NULL;
    scanf("%d",&var->data);
    if(*f==NULL)
    {
        *f=*r=var;
    }
    else
    {
        (*r)->next=var;
        *r=var;
    }
}
void deQueque(Queque **f,Queque **r)
{
    if(*f==NULL)
    {
        printf("Queque empty\n");
    }
    else if(*f==*r)
    {
       printf("%d got deleted\n",(*f)->data);
       *f=NULL;
       *r=NULL;
    }
    else
    {
        printf("%d got deleted\n",(*f)->data);
        Queque *t=*f;
        *f=(*f)->next;
        free(t);
    }
}
void display(Queque **f)
{
    if(*f==NULL)
    {
        printf("Queque empty\n");
    }
    else
    {
        printf("The elements of the Queque are:\n");
        Queque *t;
        for(t=*f;t!=NULL;t=t->next)
        {
            printf("%d ",t->data);
        }
        printf("\n");
    }
}
int main()
{
   Queque *f=NULL;
   Queque *r=NULL;
   int loop=1,c;
   while(loop)
   {
       printf("Enter choice\n");
       printf("1 for input\n");
       printf("2 for deletion\n");
       printf("3 for display\n");
       printf("0 for exit\n");
        scanf("%d",&c);
       switch(c)
       {
            case 1:
                enQueque(&f,&r);
                break;
            case 2:
                 deQueque(&f,&r);
                 break;
            case 3:
                   display(&f); 
                   break;
            case 0:
                loop=0;
                break;
            default:
                printf("Give proper values\n");
       }
   }
}
