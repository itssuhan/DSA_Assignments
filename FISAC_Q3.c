// Create a singly linked list using appropriate structure definition and generate a list of ‘n’ fibonacci numbers by successively adding the previous two values in the nodes.
// Sample output :
// Enter n: 6
// Generated list: 0->1->1->2->3->-5

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(struct node *head)
{
    struct node *temp, *newnode;
    int n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("");
}

struct node *fibonacci(struct node *head)
{
    struct node *temp, *newnode;
    int n, i, a = 0, b = 1, c;
    printf("Enter n: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = a;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        c = a + b;
        a = b;
        b = c;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    head = fibonacci(head);
    printf("Generated list: ");
    display(head);
    return 0;
}
