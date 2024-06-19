QUEUE   IMPLEMENTATION USING ARRAY




#include<stdio.h>
#include<stdlib.h>
#define SIZE 10 
int queue[SIZE];
int front =-1,rear=-1;
  void enqueue(int e)
  { 
      if(rear==SIZE-1)
    {
     printf("the queue is overflowed\n");
    }
     else{
     rear+=1;
    queue[rear]=e;
     if (front==-1)
         {
         front=0;
         }
    }
  }                                                                                                                                                                                                   


void dequeue()
{
    if(front==-1||rear==-1){
        printf("the queue is underflowed \n");
    }
    else{
        printf("the element at the front of the queue %d \n",queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front+=1;
        }
    }
}


void display(){
    printf("the elements in the queue are :\t");
    for(int i=0;i<SIZE;i++)
{
    printf("%d ",queue[i]);
}
}
int main ()
{
    while(1)
    {
    printf("\nMENU\n1.enqueue(insert)\n2.dequeue(delete)\n3.display\n4.exit the program\n");


int n;
printf("the operation you would like to do ");
scanf("%d",&n);
switch (n)
{
    case 1:
    int e;
    printf("the element or number to be inserted ");
    scanf("%d",&e);
    enqueue(e);
    display();
    break;
    case 2:
    dequeue();
    display();
    break;
    case 3:
    display();
    break;
    case 4:
    exit(0);
    default:
  printf("Invalid choice\n");
}}
}
QUEUE IMPLEMENTATON USNG ARRAY.txt
Displaying QUEUE IMPLEMENTATON USNG ARRAY.txt.2.3 Queue Using Array
2.3 Queue Using Array
Vijay K
•
Apr 24 (Edited May 3)
100 points
Due May 5, 11:59 PM
Class comments
