//Create a singly linked list. Create an exact copy of this list. Rotate the original list to the right k number times where k<= number of nodes in the list. Display the list. Now take the copy of the list rotate the list k number of times to the left where k<= number of nodes in the list . Display the modified lists.
// Sample Output:
// Input k : 2
// LIST: 3->4->5->6->7
// Left rotate: 5->6->7->3->4 Right rotate: 6->7->3->4->5

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
struct node* copy(struct node* head)
{
    struct node* current = head;    // used to iterate over the original list
    struct node* newList = NULL;    // head of the new list
    struct node* tail = NULL;       // point to the last node in a new list
 
    while (current != NULL)
    {
        // special case for the first new node
        if (newList == NULL)
        {
            newList = (struct node*)malloc(sizeof(struct node));
            newList->data = current->data;
            newList->next = NULL;
            tail = newList;
        }
        else {
            tail->next = (struct node*)malloc(sizeof(struct node));
            tail = tail->next;
            tail->data = current->data;
            tail->next = NULL;
        }
        current = current->next;
    }
 
    return newList;
}
 
// Function to rotate the list to the right by k nodes
void rotateRight(struct node** head, int k)
{
    // base case
    if (*head == NULL || k == 0) {
        return;
    }
 
    // find the length of the list
    int n = 1;
    struct node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
        n++;
    }
 
    // connect the last node to the head node
    current->next = *head;
 
    // find the (n - k % n)-th node and make it the new head
    struct node* prev = NULL;
    current = *head;
    for (int i = 0; i < n - k % n; i++)
    {
        prev = current;
        current = current->next;
    }
 
    // set the new head
    *head = current;
 
    // set the next pointer of the last node to NULL
    prev->next = NULL;
}

// Function to rotate the list to the left by k nodes

void rotateLeft(struct node** head, int k)
{
    // base case
    if (*head == NULL || k == 0) {
        return;
    }
 
    // find the length of the list
    int n = 1;
    struct node* current = *head;
    while (current->next != NULL)
    {
        current = current->next;
        n++;
    }
 
    // connect the last node to the head node
    current->next = *head;
 
    // find the (n - k % n)-th node and make it the new head
    struct node* prev = NULL;
    current = *head;
    for (int i = 0; i < k % n; i++)
    {
        prev = current;
        current = current->next;
    }
 
    // set the new head
    *head = current;
 
    // set the next pointer of the last node to NULL
    prev->next = NULL;
}

int main()
{
    struct node *head = NULL;
    struct node *head1 = NULL;
    int k;
    head = create(head);
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("LIST: ");
    display(head);
    head1 = copy(head);
    rotateRight(&head, k);
    printf("Right rotate: ");
    display(head);
    rotateLeft(&head1, k);
    printf("Left rotate: ");
    display(head1);
    return 0;
}