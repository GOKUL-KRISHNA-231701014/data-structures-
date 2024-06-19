QUEUE IMPLEMENTATION USING LINKED LIST 


#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};
struct node *front= NULL;
struct node *rear=NULL;
typedef struct node queue;
void enqueue();
void dequeue();
int display();


int main ()
{while(1){
    printf("\nMENU\n1.enqueue\n2.dequeue\n3.display\nenter the operation you would like to do\n");
    int b;
    scanf("%d",&b);
    switch(b)
    {
        case 1:
        enqueue();
        display();
        case 2:
        dequeue();
        display();
        case 3:
        display();
        case 4:
        exit(0);
        default:
        printf("invalid option exit the program...");
        exit(0);
        
    }}}
    
    void dequeue()
    {
        if(rear==NULL||front==NULL)
        {
            printf("the queue is underflow");
        }else{
            queue *temp;
            temp=front;
            if(front==rear){
                front=rear=NULL;
            }else{
                front=front->next;
                printf("%d\n",temp->data);//prints the element to be deleted//
                free(temp);
            }
        }
    }
    
    void enqueue ()
    {
        printf("enter the element to insert in the queue");
        int e;
        scanf("%d",&e);
        queue *newnode=malloc(sizeof(queue));
        newnode->data=e;
        newnode->next=NULL;
        if(front=rear)
        {
            front=rear=newnode;
        }else{
        rear->next=newnode;
        rear=newnode;
    } }
    
int display()
{
    if(front==NULL)
    {
        printf("Queue is Underflow...!\n");
    }else
    {
        queue *pos;
        pos=front;
        while(pos!=NULL)
        {printf("%d\t", pos->data);
        pos=pos->next;}
        printf("\n");
    }
}
QUEUE IMPLEMENTATION USING LINKED LIST .txt
Displaying QUEUE IMPLEMENTATION USING LINKED LIST .txt.2.4 Queue Using List
2.4 Queue Using List
Vijay K
•
Apr 24 (Edited May 3)
100 points
Due May 5, 11:59 PM
Class comments
