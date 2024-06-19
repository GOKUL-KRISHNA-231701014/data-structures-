Conversion from infix to postfix expression 


#include<stdio.h>
#include<string.h>
#define MAX 30
char expr[MAX];
char stack[MAX];
int top=-1;
void push( char symbol);
char pop();
int priority(char symbol);


int main()
{
    printf("enter the expression to convert from infix to postfix :");
    scanf("%s",expr);
    for(int i=0;i<strlen(expr);i++){
        if(expr[i]>='a' && expr[i]<='z'){
        printf("%c",expr[i]);
        }
        else if(expr[i]=='('){
            push(expr[i]);
        }
        else if (expr[i]==')'){
            while(stack[top]!='('){
                printf("%c",pop());// used to remove the exprtession until open parenthesis //
            }
            pop();/* as the elements before open paranthesis is removed
            it's time to remove the open paranthesis */
}
else
{
while(priority(expr[i])<=priority(stack[top]) && top!=-1)
printf("%c", pop());
push(expr[i]);
}
}
        for(int i = top; i >= 0; i--){
          printf("%c", pop());
        }


    }


void push(char symbol){
    top+=1;
    stack[top]=symbol;
}


char pop()
{
    char ch;
    ch=stack[top];
    top--;
    return ch;
    }
    
int priority(char symbol){
    int k;
    switch(symbol)
    {
        case '(':
        k=0;
        break;
        case '+':
        case '-':
        k=1;
        break;
        case '*':
        case '/':
        case '%':
        k=2;
        break;
    }
    return k;
}
infix to postfix conversion.txt
Displaying infix to postfix conversion.txt.
2.5 Infix to Post fix conversion
Vijay K
•
May 3 (Edited May 3)
100 points
Due May 8, 11:59 PM
Class comments
