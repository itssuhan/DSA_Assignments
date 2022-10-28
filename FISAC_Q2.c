#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void rotate(struct Node **head_ref, int k);

void push(struct Node **head_ref, int new_data)
{

    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(void)
{
    struct Node *head = NULL;

    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);

    printf("\nGiven list \n");
    printList(head);
    rotate(&head, 2); //k=2

    printf("\nLeft Rotated Linked List \n");
    printList(head);

    return (0);
}

void rotate(struct Node **head_ref, int k)
{
    if (k == 0)
        return;

    struct Node *current = *head_ref;

    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL)
        return;

    struct Node *kthNode = current;

    while (current->next != NULL)
        current = current->next;

    current->next = *head_ref;

    *head_ref = kthNode->next;

    kthNode->next = NULL;
}