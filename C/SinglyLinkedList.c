#include <stdio.h>  
#include <stdlib.h>  

struct node{  
    int data;  
    struct node *next;   
};  

struct node *head;

void addNode(int value){
    struct node *current, *temp;
    current = (struct node *) malloc(sizeof(struct node *)); 
    current->data = value;
    if(current == NULL){  
        printf("Invalid!");   
    } else{
        if(head == NULL){
            current->next = NULL;
            head = current;
        } else{
            temp = head;  
            while (temp->next != NULL){  
                temp = temp -> next;  
            }  
            temp->next = current;  
            current->next = NULL;
        }
    }
}
void display(){  
    struct node *current;  
    current = head;   
    if(current == NULL){  
      printf("List is empty\n");
    }else{  
        printf("Nodes of singly linked list: ");   
        while (current != NULL){  
            printf("%d ",current->data);  
            current = current->next;  
        }  
    }  
}

int main() {  
    addNode(1); 
    addNode(2);
    addNode(3);
    addNode(4);

    display();

    return 0;
}  
