#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char *data;
    struct Node *next;
};
void display(struct Node *first)
{
    struct Node *temp = first;
    while(temp != NULL)
    {
    printf("%s\n",temp->data);
     temp = temp->next;
    }
}
struct Node *insert_rear(char *ele,struct Node *first)
{
   struct Node *ptr;
   ptr = (struct Node *)malloc(sizeof(struct Node *));
   ptr->data =  (char *)malloc(10*sizeof(char));
   ptr->data = ele;
   if(first == NULL)
   {
    ptr->next = NULL;
    return ptr;
   }
   struct Node *temp = first;
   while(temp->next != NULL)
   {
    temp = temp->next;
   }
   temp->next = ptr;
   ptr->next = NULL;
   return first;
}
int isPalindrome(char *str, int start, int end){
   
    if(NULL == str || start < 0 || end < 0)
    {
         return 0;
    }
     if(start >= end)
         {
             return 1;
         }
     if(str[start] == str[end]){
         return isPalindrome(str, start + 1, end - 1);
     }
     return 0;
 }
 struct Node *palindrome(struct Node *head,struct Node *head1)
 {
    struct Node *temp1 = head;
    int n; 
      char *s1;
    while(temp1 != NULL)
    {
       if(isPalindrome(temp1->data,0,strlen(temp1->data)-1))
       {
         s1 =  (char *)malloc(10*sizeof(char));
         s1 = temp1->data;   
        head1 = insert_rear(s1,head1);
         temp1 = temp1->next; 
       }
       else
       {
        temp1 = temp1->next;
       }
    }
       return head1;
 }
 struct Node *notpalindrome(struct Node *head,struct Node *head2)
 {
    struct Node *temp1 = head;
    int n;
      char *s1;
    while(temp1 != NULL)
    {
       if(!(isPalindrome(temp1->data,0,strlen(temp1->data)-1)))
       {
         s1 =  (char *)malloc(10*sizeof(char));
         s1 = temp1->data;
        head2 = insert_rear(s1,head2);
        temp1 = temp1->next;
       }
       else
       {
        temp1 = temp1->next;
       }
    }
       return head2;
 }
int main()
{
    struct Node *head;
    struct Node *head1;
    struct Node *head2;
    head = (struct Node *)malloc(sizeof(struct Node *));
    head1 = (struct Node *)malloc(sizeof(struct Node *));
    head2 = (struct Node *)malloc(sizeof(struct Node *));
    head = NULL;
    head1 = NULL;
    head2 = NULL;
     printf("Enter number of words\n");
    int n,i;
    scanf("%d",&n);
    char *s1;
    printf("Enter words\n");
        for(i=0;i<n;i++)
        {
            s1 =  (char *)malloc(10*sizeof(char));
            scanf("%s",s1);
            head = insert_rear(s1,head);
        }
    printf("List of words :\n");
    display(head);
    head1=palindrome(head,head1);
    printf("List containing palindromes :\n");
    display(head1);
     head2=notpalindrome(head,head2);
     printf("List containing non palindromes :\n");
     display(head2);
    return 0;
}