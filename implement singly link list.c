#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};
struct node* start = NULL;

void createList() {
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            newnode->link = NULL;
            start = newnode;
            temp = start;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &data);
            start->info = data;

            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                newnode->link = NULL;
                temp->link = newnode;
                printf("\nEnter number to be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    } else {
        printf("\nThe list is already created\n");
    }
}

void traverse() {
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        while (temp != NULL) {
            printf("Data = %d\n", temp->info);
            temp = temp->link;
        }
    }
}

void insertAtFront() {
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->info = data;
    temp->link = start;
    start = temp;
}

void insertAtEnd() {
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->link = NULL;
    temp->info = data;
    if (start == NULL) {
        start = temp;
        return;
    }
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

void insertAtPosition() {
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
    newnode->info = data;
    newnode->link = NULL;
    temp = start;
    if (pos == 1) {
        newnode->link = start;
        start = newnode;
        return;
    }
    while (i < pos - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }
    if (temp == NULL) {
        printf("\nPosition not found!\n");
        return;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void deleteFirst() {
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else if (start->link == NULL) {
        free(start);
        start = NULL;
        return;
    } else {
        temp = start;
        while (temp->link != NULL) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = NULL;
    }
}

void deletePosition() {
    struct node *temp, *position;
    int i = 1, pos;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        printf("\nEnter index : ");
        scanf("%d", &pos);
        temp = start;
        if (pos == 1) {
            start = start->link;
            free(temp);
            return;
        }
        while (i < pos - 1 && temp != NULL) {
            temp = temp->link;
            i++;
        }
        if (temp == NULL || temp->link == NULL) {
            printf("\nPosition not found!\n");
            return;
        }
        position = temp->link;
        temp->link = position->link;
        free(position);
    }
}

void maximum() {
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node* temp = start;
        int max = temp->info;
        while (temp != NULL) {
            if (max < temp->info)
                max = temp->info;
            temp = temp->link;
        }
        printf("\nMaximum number is : %d\n", max);
    }
}

void mean() {
    if (start == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node* temp = start;
        int sum = 0, count = 0;
        float m;
        while (temp != NULL) {
            sum = sum + temp->info;
            temp = temp->link;
            count++;
        }
        m = (float)sum / count;
        printf("\nMean is %f \n", m);
    }
}

void sort() {
    struct node* current = start;
    struct node* index = NULL;
    int temp;
    if (start == NULL)
        return;
    else {
        while (current != NULL) {
            index = current->link;
            while (index != NULL) {
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
            current = current->link;
        }
    }
}

void reverseLL() {
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
    if (start == NULL)
        printf("List is empty\n");
    else {
        while (start != NULL) {
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
        temp = start;
        printf("Reversed linked list is : ");
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->link;
        }
        printf("\n");
    }
}

void search() {
    int found = 0;
    struct node* tr = start;
    if (start == NULL) {
        printf("Linked list is empty\n");
    } else {
        printf("\nEnter the element you want to search: ");
        int key;
        scanf("%d", &key);
        while (tr != NULL) {
            if (tr->info == key) {
                found = 1;
                break;
            }
            tr = tr->link;
        }
        if (found)
            printf("Yes, %d is present in the linked list.\n", key);
        else
            printf("No, %d is not present in the linked list.\n", key);
    }
}

int main() {
    createList();
    int choice;
    while (1) {
        printf("\n\t1 To see list\n");
        printf("\t2 For insertion at starting\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of first element\n");
        printf("\t6 For deletion of last element\n");
        printf("\t7 For deletion of element at any position\n");
        printf("\t8 To find maximum among the elements\n");
        printf("\t9 To find mean of the elements\n");
        printf("\t10 To sort element\n");
        printf("\t11 To reverse the linked list\n");
        printf("\t12 Search an element in linked list\n");
        printf("\t13 To exit\n");
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                traverse();
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deletePosition();
                break;
            case 8:
                maximum();
                break;
            case 9:
                mean();
                break;
            case 10:
                sort();
                break;
            case 11:
                reverseLL();
                break;
            case 12:
                search();
                break;
            case 13:
                exit(1);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }
    return 0;
}


