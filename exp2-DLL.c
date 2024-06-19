#include<stdio.h>
#include<stdlib.h>
struct node
	 {
		 struct node *next,*prev;
		 int Element;
	 };
	 struct node *find(struct node *list,int e);
	 struct node *findprev(struct node *list,int e);
	 void display(struct node *list); 
     void insertbeg(struct node *list,int e);
     void insertmiddle(struct node *list,int p,int e);
	 void insertlast(struct node *list,int e);
	 void delbeg(struct node *list);
	 void delmid(struct node *list,int e);
	 void dellast(struct node *list);
int main()
{
    int ch,p,e;
	 struct node*list;
	 list=malloc(sizeof(struct node));
	 list->next=NULL;
      printf("MENU FOR SINGLE LINKED LIST :");
      printf("\n------------------------");
      printf("\n1->INSERT BEGINNING");
      printf("\t\n2->INSERT MIDDLE");
      printf("\t\n3->INSERT LAST");
      printf("\t\n4->DELETE BEGINNING");
      printf("\t\n5->DELETE MIDDLE");
      printf("\t\n6->DELETE LAST");
	  printf("\n7->TRAVERSE THE LIST");
      printf("\n------------------------");
	  while(1){
      printf("\n\nENTER YOUR CHOICE :");
      scanf("%d",&ch);
	 switch(ch)
	 {
	    case 1:
		  printf("ENTER THE ELEMENT TO BE INSERTED :");
		  scanf("%d",&e);
		  insertbeg(list,e);
		  printf("\nOPERATION IS DONE");
		  break;
		case 2:
		   printf("ENTER THE ELEMENT TO BE INSERTED:");
		   scanf("%d",&e);
		   printf("ENTER THE POSITION  TO INSERT:");
		   scanf("%d",&p);
		   insertmiddle(list,p,e);
           printf("\nOPERATION IS DONE");
		   break;
		case 3:
		     printf("ENTER THE ELEMENT TO BE INSERTED:");
		     scanf("%d",&e);
		     insertlast(list,e);
		     printf("\nOPERATION IS DONE");
             break;
        case 4:
             delbeg(list);
			 printf("\nOPERATION IS DONE");
             break;
        case 5:
             printf("ENTER THE ELEMENT TO DELETE:");
             scanf("%d",&e);
             delmid(list,e);
			 printf("\nOPERATION IS DONE");
             break;
        case 6:
             dellast(list);
	         printf("\nOPERATION IS DONE");
             break;
		case 7:
			 printf("\nOPERATION IS DONE");
			 display(list);
		     break;
	 }
}
}

struct node *find(struct node *list,int e)
{
    struct node *position;
    position=list->next;
    while(position!=NULL&&position->Element!=e)
    {
        position=position->next;
    }
    return position;
   
}
struct node *findprev(struct node *list,int e)
{
    struct node *position;
    position=list->next;
    while(position->next!=NULL&&position->next->Element!=e)
    {
        position=position->next;
    }
    return position;
}
void insertbeg(struct node *list,int e)
{
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->Element=e;
    if(list->next==NULL){
       newnode->next=NULL;
       newnode->prev=list;
       list->next=newnode;
    }
    else{
      newnode->next=list->next;
      newnode->prev=list;
      list->next->prev=newnode;
      list->next=newnode;
}}
void insertmiddle(struct node *list,int p,int e)
{
    struct node *newnode;
    struct node *position;
    newnode=malloc(sizeof(struct node));
    
    position=find(list, p);
    newnode->Element=e;
    newnode->next=position->next;
    newnode->prev=position;
    position->next->prev=newnode;
    position->next=newnode;
    
}
void insertlast(struct node *list,int e)
{
    struct node *position;
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    newnode->Element=e;
    newnode->next=NULL;
    if(list->next==NULL)
    {
        newnode->prev=list;
        list->next=newnode;
    }
    else
    {
        position=list;
        while(position->next!=NULL)
        {
            position=position->next;
        }
        newnode->prev=position;
        position->next=newnode;
    }
    
}
void delbeg(struct node *list)
{
    if(list->next==NULL)
    {
        printf("THE LIST IS EMPTY");
    }
    else
    {
          struct node *tempnode;
          tempnode=list->next;
          list->next=tempnode->next;
          if(tempnode->next!=NULL)
          {
              tempnode->next->prev=list;
          }
          free(tempnode);
    }
}
void delmid(struct node *list,int e)
{
    if(list->next==NULL)
    {
        printf("THE LIST IS EMPTY");
    }
    else
    {
        struct node *tempnode;
        struct node *position;
        position=find(list,e);
         if(list->next!=NULL)
		 {
		    tempnode=position;
            position->next->prev=tempnode->prev;
            position->prev->next=tempnode->next;
            free(tempnode);
		 }
    }
    
}
void dellast(struct node *list)
{
    if(list->next==NULL)
    {
        printf("THE LIST IS EMPTY");
    }
    else
    {
         struct node *tempnode;
         struct node *position;
         position=list->next;
         while(position->next->next!=NULL)
         {
             position=position->next;
         }
        tempnode=position;
		position->prev->next=NULL;
        free(tempnode);
    }
}
void display(struct node *list){
	     struct node *position;
	     if(list->next!=NULL){
	       position=list->next;
	       printf("\nELEMENTS ARE ->");
	       while(position!=NULL)
	       {
	         printf(" %d",position->Element);
	         position=position->next;
	       }
	     }
	     else{
	         printf("THE LIST IS EMPTY");
	     }
	 }