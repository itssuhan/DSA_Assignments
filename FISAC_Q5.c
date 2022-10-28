#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int data;
  struct Node *next;
};

void display(struct Node *first)
{
  if (first == NULL)
  {
    printf("List is empty\n");
    exit(0);
  }
  printf("Contents of list are\n");
  while (first != NULL)
  {
    printf("%d\n", first->data);
    first = first->next;
  }
}

struct Node *insert_rear(int ele, struct Node *first)
{
  struct Node *ptr;
  ptr = (struct Node *)malloc(sizeof(struct Node *));
  ptr->data = ele;
  if (first == NULL)
  {
    ptr->next = NULL;
    return ptr;
  }
  struct Node *temp = first;
  ;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = ptr;
  ptr->next = NULL;
  return first;
}
struct Node *delete_front(struct Node *first)
{
  if (first == NULL)
  {
    printf("List is empty\n");
    exit(0);
  }
  struct Node *t = first->next;
  free(first);

  return t;
}
struct Node *delete_rear(struct Node *first)
{
  struct Node *temp1 = first;
  struct Node *temp2 = first->next;
  while (temp2->next != NULL)
  {
    temp2 = temp2->next;
    temp1 = temp1->next;
  }
  temp1->next = NULL;
  free(temp2);
  return first;
}
struct Node *deletemiddle(struct Node *head, struct Node *ptr)
{
  struct Node *temp = head->next;
  struct Node *temp1 = head;
  while (temp != ptr)
  {
    temp = temp->next;
    temp1 = temp1->next;
  }
  temp1->next = temp->next;
  free(temp);
  return head;
}
struct Node *delete_occurence(struct Node *head, int k)
{
  int key;
  key = k * k;
  struct Node *ptr = head->next;
  struct Node *ptr1 = head;
  struct Node *ptr2 = head;
  while (ptr != NULL)
  {
    if (ptr->data == key && ptr->next == NULL)
    {
      head = delete_rear(head);
      ptr = ptr->next;
      ptr1 = ptr1->next;
    }
    else if (ptr->data == key && ptr->next != NULL)
    {
      head = deletemiddle(head, ptr);
      ptr = ptr->next;
      ptr1 = ptr1->next;
    }
    else
    {
      ptr = ptr->next;
      ptr1 = ptr1->next;
    }
  }
  if (ptr2->data == key)
  {
    head = delete_front(head);
  }
  return head;
}
int main()
{
  struct Node *head;
  head = (struct Node *)malloc(sizeof(struct Node *));
  int choice, n, t, k;
  do
  {
    printf("Enter 1 to create linked list\n");
    printf("Enter 2 delete occurences of linked list\n");
    printf("Enter 3 to display linked list\n");
    printf("Enter 4 to terminate\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      head = NULL;
      printf("Enter number of elements \n");
      scanf("%d", &n);
      printf("Enter elements \n");
      for (int i = 0; i < n; i++)
      {
        scanf("%d", &t);
        head = insert_rear(t, head);
      }
      break;
    case 2:
      printf("Enter key\n");
      scanf("%d", &k);
      head = delete_occurence(head, k);
      break;
    case 3:
      display(head);
      break;
    case 4:
      exit(0);
    }
  } while (1);
}