#include <stdio.h>
#include <malloc.h>
typedef struct node {
    int val;
    struct node * next;
} node_t;




void add_first(node_t** head, int var){

    node_t * new = (node_t *) malloc(sizeof(node_t));
    new ->val = var;
    new->next = * head;
    * head = new;
    
}

void printList(node_t * head){
    node_t * current = head;
    
    while(current != NULL){
        printf("%d\n",current->val);
        current = current->next;
    }
}


int main()
{
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) {
        return 1;
    }
    
    head->val = 1;
    head->next = (node_t *) malloc(sizeof(node_t));
    
    
    //Zadanie 1
    printf("Zadanie 1\n");
    add_first(&head, 8);
    add_first(&head, 8);
    
    printList(head);
    
    //Zadanie 2
    
    
    
    return 0;
}
