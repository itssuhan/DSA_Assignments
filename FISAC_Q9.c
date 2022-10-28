#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct Node
struct Node {
    char data;
    struct Node* next;
};

// pointer to the node
typedef struct Node *Nodeptr;


// Create Singly linked List from the given name
Nodeptr create(char name[]){
    
    // create empty head node
    Nodeptr head = NULL;
    
    // Iterate through all the characters in the given name
    for(int index = 0; index < strlen(name); index++){
        // create a new node
        Nodeptr newNode = malloc(sizeof(struct Node));
        newNode->data = name[index];
        newNode->next = NULL;
        
        // if head is empty, make the newNode as head
        if (head == NULL) {
            head = newNode;
        } else {
            // Iterate through the list and find last node in the list
            Nodeptr temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            // insert the new node at the end
            temp->next = newNode;
        }
    }
    
    return head;
}

void allVowels(Nodeptr* head){
    
    if(head != NULL){
        // Remove vowles from head node
        char currentChar = (*head)->data;
        while((*head) != NULL && (currentChar == 'a' ||currentChar == 'A' 
            || currentChar == 'e' || currentChar == 'E' 
            || currentChar == 'i' || currentChar == 'I' 
            || currentChar == 'o' || currentChar == 'O' 
            || currentChar == 'u' || currentChar == 'U')){
                
                (*head) = (*head)->next;
                currentChar = (*head)->data;
            }
        
        if(head != NULL){
           
            // Iterate through the remaining nodes
            Nodeptr temp = (*head);
            Nodeptr prev = NULL;
            while(temp != NULL){
                currentChar = temp->data;
                if(currentChar == 'a' ||currentChar == 'A' 
                    || currentChar == 'e' || currentChar == 'E' 
                    || currentChar == 'i' || currentChar == 'I' 
                    || currentChar == 'o' || currentChar == 'O' 
                    || currentChar == 'u' || currentChar == 'U'){
                        prev->next = temp->next;
                    }
                    else{
                         prev = temp;
                    }
                
               
                temp = temp->next;
            }
        }
    }
}


// prints the list
void printList(Nodeptr head){
    Nodeptr temp = head;
    while(temp->next != NULL){
        printf("%c->", temp->data);
        temp = temp->next;
    }
    if(temp != NULL){
        printf("%c", temp->data);
        
    }
    printf("\n");
}

int main()
{
    char* s = "Suhan";
    Nodeptr head = create(s);
    printList(head);
    allVowels(&head);
    printList(head);

    return 0;
}