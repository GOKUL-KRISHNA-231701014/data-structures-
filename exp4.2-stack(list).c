#   Stack using list






#include<stdio.h>
#include<stdlib.h>
struct node
{
int element;
struct node*next;
};
struct node*top=NULL;
void push()
{
struct node *newnode=malloc(sizeof(struct node));
if(newnode==NULL)
printf("Stack is Overflowed");
else
   {
int e;
scanf("%d",&e);
newnode->element=e;
if(top==NULL)
newnode->next=NULL;
else
{
newnode->next=top;
top=newnode;
}
}
}
void pop()
{
    if(top==NULL)
        printf("The Stack is Underflowed");
    else
{
        struct node *tempnode=top;
top=top->next;
free(tempnode);
}
}
void display()
{
    struct node *position=top;
for(;position!=NULL;)
{
        printf("%d",position->element);
        position=position->next;
}
}
int main()
{
int c;


while(1)
{
        printf("\nMENU\n1.INSERT ELEMENT\n2.DELETE ELEMENT\n3.DISPLAY STACK\n4.EXIT\n");
        printf("Enter the choice(1/2/3/4):");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice!!");
        }
    }
    return 0;
}
STACK USING LIST .txt
Displaying STACK USING LIST .txt.2.2 Stack using List
