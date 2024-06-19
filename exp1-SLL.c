#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void insertbegin(Node *list, int e);
void insertmid(Node *list, int e, int p);
void insertlast(Node *list, int e);
void delbegin(Node *list);
void delmid(Node *list, int e);
void dellast(Node *list);
int display(Node *list);
Node *Find(Node *list, int p);
Node *FindPrevious(Node *list, int x);

int main() {
    Node *list = malloc(sizeof(Node));
    list->next = NULL;

    int n, e, p;
    while (1) {
        printf("\nMENU\n1. Insert at beginning\n2. Insert at middle\n3. Insert at end\n");
        printf("4. Delete at beginning\n5. Delete at middle\n6. Delete at end\n");
        printf("7. Display\n8. Exit the program\nEnter the operation you would like to do: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &e);
                insertbegin(list, e);
                display(list);
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", &e);
                printf("Enter the position: ");
                scanf("%d", &p);
                insertmid(list, e, p);
                display(list);
                break;
            case 3:
                printf("Enter the element: ");
                scanf("%d", &e);
                insertlast(list, e);
                display(list);
                break;
            case 4:
                delbegin(list);
                display(list);
                break;
            case 5:
                printf("Enter the element to be deleted: ");
                scanf("%d", &e);
                delmid(list, e);
                display(list);
                break;
            case 6:
                dellast(list);
                display(list);
                break;
            case 7:
                display(list);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid operation\n");
        }
    }

    return 0;
}

void insertbegin(Node *list, int e) {
    Node *newnode = malloc(sizeof(Node));
    newnode->data = e;
    newnode->next = list->next;
    list->next = newnode;
}

void insertmid(Node *list, int e, int p) {
    Node *newnode = malloc(sizeof(Node));
    newnode->data = e;

    Node *position = Find(list, p);
    if (position != NULL) {
        newnode->next = position->next;
        position->next = newnode;
    } else {
        printf("Position not found\n");
        free(newnode);
    }
}

void insertlast(Node *list, int e) {
    Node *newnode = malloc(sizeof(Node));
    newnode->data = e;
    newnode->next = NULL;

    if (list->next == NULL) {
        list->next = newnode;
    } else {
        Node *temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void delbegin(Node *list) {
    if (list->next != NULL) {
        Node *temp = list->next;
        list->next = temp->next;
        printf("Deleted item: %d\n", temp->data);
        free(temp);
    } else {
        printf("List is empty\n");
    }
}

void delmid(Node *list, int e) {
    if (list->next != NULL) {
        Node *prev = FindPrevious(list, e);
        if (prev != NULL && prev->next != NULL) {
            Node *temp = prev->next;
            prev->next = temp->next;
            printf("Deleted item: %d\n", temp->data);
            free(temp);
        } else {
            printf("Element %d not found\n", e);
        }
    } else {
        printf("List is empty\n");
    }
}

void dellast(Node *list) {
    if (list->next != NULL) {
        Node *prev = list;
        Node *temp = list->next;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        printf("Deleted item: %d\n", temp->data);
        free(temp);
    } else {
        printf("List is empty\n");
    }
}

int display(Node *list) {
    if (list->next == NULL) {
        printf("List is empty\n");
        return 0;
    }

    Node *temp = list->next;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 1;
}

Node *Find(Node *list, int p) {
    Node *temp = list->next;
    while (temp != NULL && temp->data != p) {
        temp = temp->next;
    }
    return temp;
}

Node *FindPrevious(Node *list, int x) {
    Node *temp = list;
    while (temp->next != NULL && temp->next->data != x) {
        temp = temp->next;
    }
    return temp;
}
