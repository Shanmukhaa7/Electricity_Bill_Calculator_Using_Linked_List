#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char housen[25];
    float units;

    struct Node* next;
}*head;

void printList(struct Node* n)
{
    while (n->next != NULL) {
        printf("House Number : %s\nUnits used : %f\n\n", n->housen,n->units);
        n = n->next;
    }

}

void push()
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the House Number : ");
    scanf("%s",new_node->housen);
    printf("Enter the units used : ");
    scanf("%f",&new_node->units);
    new_node->next = head;

    head = new_node;

    printf("\n\n\n");
}

void deleteNode(struct Node* head_ref)
{
    char key[25];
    printf("Enter House Number to delete : ");
    scanf("%s",key);
    struct Node *temp = head_ref, *prev;

    if (temp != NULL && strcmp(temp->housen,key) == 0) {
        head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->housen, key) !=0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
    prev->next = temp->next;

    free(temp);
    printf("\n\n\n");
}

float calculateBill(float units){
    float bill;

	if(units<=50 && units>=0)
	{
		bill=units*3.50;
	}
	else if(units<=100 && units>50)
	{
		bill=50*3.50+(units-50)*4;

	}
	else if(units<=250 && units>150)
	{
		bill=50*3.50+100*4+(units-150)*5.20;

	}

	else if(units>250)
	{
		bill=50*3.50+100*4+100*5.20+(units-250)*6.50;

	}
	else
	{
		printf("Please enter valid consumed units...");
	}
    return bill;
}

void search(struct Node* head)
{
    char x[25];
    printf("Enter House Number to calculate Bill  : ");
    scanf("%s",x);
    int found = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (strcmp(current->housen,x) == 0){
            printf("Current units used : %f\n",current->units);
            float b = calculateBill(current->units);
            printf("The Bill is : %f\n",b);
            found = 1;
        }
        current = current->next;
    }

    if(found == 0){
        printf("Cant find the House Number given");
    }

    printf("\n\n\n");
}

void update(struct Node* head)
{
    char x[25];
    printf("Enter House Number to update : ");
    scanf("%s",x);
    int found = 0;
    struct Node* current = head;

    while (current != NULL) {
        if (strcmp(current->housen,x) == 0){
            printf("Enter new amount of units : ");
            scanf("%f",&current->units);
            printf("Values Updated!");
            found = 1;
        }
        current = current->next;
    }

    if(found == 0){
        printf("Cant find the House Number given");
    }

    printf("\n\n\n");
}

int main()
{
    head = (struct Node *)malloc(sizeof(struct Node));
    int c;
    int b = 0;

    while(1){
    printf("1 - Insert\n");
    printf("2 - Delete\n");
    printf("3 - Print\n");
    printf("4 - Search House Number To Get Bill \n");
    printf("5 - Update\n");
    printf("6 - EXIT\n");
    printf("Enter your choice : ");
    scanf("%d",&c);
    system("clear");

    switch(c){
        case 1:
            push(head);
            break;
        case 2:
            deleteNode(head);
            break;
        case 3:
            printList(head);
            break;
        case 4:
            search(head);
            break;
        case 5:
            update(head);
            break;
        case 6:
            b = 1;
            break;
        default:
            continue;
    }

    if(b==1){
        break;
    }

    }

    return 0;
}
