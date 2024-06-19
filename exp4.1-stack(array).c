STACK USING ARRAY 




#include <stdio.h>
#include,stdlib.h>


#define MAX 5
int stack[MAX],top=-1;
void push ();
void pop();
int display();
int main ()
{
while(22){
    printf("\nMENU \n1.push\n2.pop\n3.display\n4.exit the program \noperation you would like to do\n ");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        push();
        display;
        break;
        case 2:
        pop();
        display();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("operation not defined clearly");
        exit(0);
        
    }
}}
void push()
{
    printf("enter the element you like to add");
    int e;
    scanf("%d",&e);
    if(top==MAX-1){
        printf("the stack is overflow");
    }
    else{
        top+=1;
        stack[top]=e;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("the stack is underflow");
    }else{
        printf("%d\n",stack[top]);
        top--;
    }
}
int display()
{
    for(int i=0;i<MAX;i++)//this will print the full stack //
    {
        printf("%d ,stack[i]");
        printf("\n");
    }
}
stack using array.txt
Displaying stack using array.txt.2.1 Stack Using Array
2.1 Stack Using Array
Vijay K
•
Apr 24 (Edited May 3)
10 points
Due May 5, 11:59 PM
Class comments
